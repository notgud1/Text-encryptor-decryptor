#pragma once
#include "Cipher.h"
#include "Substitution.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // For std::shuffle
#include <random>    // For std::random_device and std::mt19937


/*
This class performs the Mono Alpha substition.

This is an encryption method that encrypts/decrypts by using a FIXED translation table. 


for this example the user will input their own translation table for the program to follow 
*/
class MonoAlphaSubstitution :  Cipher
{
private:
	std::unordered_map<char,char> map; // encryption map
	std::unordered_map<char, char> reverse_map; //decryption map
	std::string alphabet = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };

public:
	// Default constructor. Every letter is mapped to a random character
	MonoAlphaSubstitution() {
		// Create a randomized alphabet
		std::string randomized_alphabet = alphabet;

		// Shuffle the alphabet
		std::random_device rd;   // obtain a random number from hardware
		std::mt19937 g(rd());    // seed the generator
		std::shuffle(randomized_alphabet.begin(), randomized_alphabet.end(), g); // shuffle the alphabet

		// Map each character in the original alphabet to a shuffled one for encryption
		for (size_t i = 0; i < alphabet.length(); ++i) {
			map[alphabet[i]] = randomized_alphabet[i];
			reverse_map[randomized_alphabet[i]] = alphabet[i]; // Create reverse map for decryption
		}
	}

	// Encrypt a single character
	char encrypt(char c) {
		if (map.find(c) != map.end()) {
			return map[c]; // Return the encrypted character
		}
		return c; // Return original if character not found in the map
	}

	// Decrypt a single character
	char decrypt(char c) {
		if (reverse_map.find(c) != reverse_map.end()) {
			return reverse_map[c]; // Return the decrypted character
		}
		return c; // Return original if character not found in the reverse map
	}

	// Print out the mapping for debugging
	void printMapping() {
		for (char c : alphabet) {
			std::cout << c << " -> " << map[c] << std::endl;
		}
	}


};

int main() {

	MonoAlphaSubstitution substitution;

	// Print the random mapping
	substitution.printMapping();

	// Encrypt a sample text
	std::string original_text = "Living.";
	std::string encrypted_text;
	for (char c : original_text) {
		encrypted_text += substitution.encrypt(c);
	}

	std::cout << "Original: " << original_text << std::endl;
	std::cout << "Encrypted: " << encrypted_text << std::endl;

	// Decrypt the text
	std::string decrypted_text;
	for (char c : encrypted_text) {
		decrypted_text += substitution.decrypt(c);
	}

	std::cout << "Decrypted: " << decrypted_text << std::endl;

	return 0;

}



