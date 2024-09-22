#pragma once
#include "Cipher.h"
#include "Substitution.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // For std::shuffle
#include <random>    // For std::random_device and std::mt19937
#include <fstream>


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


	//Creates a decryption map that allows us to decrypt text later on
	void decryptwithkey(std::string key) {
		reverse_map.clear(); // Clear the current reverse map
		for (int i = 0; i < alphabet.size(); i++) {
			reverse_map[key[i]] = alphabet[i];
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

	// Print out the mapping for debugging. 
	void printMapping() {
		for (char c : alphabet) {
			std::cout  << c << " -> " << map[c] << " ";
		}
	}

	// store the mapping for file save 
	std::string CreateMappingKey() {
		std::string key;
		for (char c : alphabet) {
			key += map[c];
		}
		return key;
	}

};

//stores the encrypted word, and the key in a file
void storeEncryptedInfotoFile(std::string word) {
	MonoAlphaSubstitution new_word;				// initialse class for us to create everything
	std::string encrypted_word;
	std::string encrypted_text;
	
	for (char c : word) {
		encrypted_text += new_word.encrypt(c);
	}

	std::string key;
	key = new_word.CreateMappingKey();


	// creates the location of where the encrypted data will be saved (The std::ios::add allows us to save multip
	//-le versions of the encrypted data
	std::ofstream file("C:\\Users\\mirsa\\OneDrive\\Desktop\\Coding projects\\Encrypted text.txt", std::ios::app);


	// Check if the file was successfully opened
	if (!file.is_open()) {
		std::cerr << "Error: Could not open the file at the specified path." << std::endl;
		return;
	}


	//this just adds the variables to the .txt file
	file <<"Original: " << word << "\n"<< "Encrypted: " << encrypted_text << "\n" << "Key: " << key << "\n\n";
	file.close();

}
