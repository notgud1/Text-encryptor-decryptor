#pragma once
#include "Cipher.h"
#include "Substitution.h"
#include <vector>
#include <string>


/*
This class performs the Mono Alpha substition.

This is an encryption method that encrypts/decrypts by using a FIXED translation table. 


for this example the user will input their own translation table for the program to follow 
*/
class MonoAlphaSubstitution :  Cipher
{
private:
	std::string map; // this vec stores the mapping key that will be used to encrypt/decrypt the text 

public:
	std::string alphabet[27] = { "abcdefghijklmnopqrstuvwxyz"};

	// default contructor. // every letter is mapped to itself
	MonoAlphaSubstitution() {
		std::string map = this->map; 
	}

	/*
	This constructor takes a string and creates a mapping where each character at an odd index maps to the one before it. Unmapped characters map to themselves.
	For example, "ABBCCD" maps A -> B, B -> C, C -> D. An empty string results in all characters mapping to themselves. This works for any characters, not just letters.
	*/
	MonoAlphaSubstitution(std::string str) {
		std::string map = this->map;

	}

	/// <summary>
	/// takes a char and encrypts it
	/// </summary>
	/// <param name="c"></param>
	/// <returns></returns>  encrypted char
	char& encrypt(char c) {
		int alphabet_size = alphabet->size();
		for (int t =0;t<alphabet_size;t++)
		char current_key = c;

		for (int i = 0; i < map.size(); i ++ ) {  // iterates through the key to encrypt the selected char

			char current_key = map[tolower(i)];

			if (current_key == c ) {
				c = map[i + 1];
			}

		}
		return c;
		
	}

	//decrypts char by key

	char& decrypt(char c) {

		for (int i = 0; i < map.size(); i++) {  // iterates through the key to encrypt the selected char

			char current_key = map[i];

			if (current_key == c && i % 2 != 0) {
				c = map[i - 1];
			}

		}
		return c;

	}


	// Method to handle command-line style arguments
	void processArgs(const std::vector<std::string>& args) {
		if (args.size() < 3) {
			std::cout << "Too few parameters!\nUsage: MonoAlphaSubstitution encrypt key \"cipher text\"" << std::endl;
		}
		else if (args.size() > 3) {
			std::cout << "Too many parameters!\nUsage: MonoAlphaSubstitution encrypt key \"cipher text\"" << std::endl;
		}
		else {
			std::string eord = args[0];
			std::string key = args[1];
			std::string text = args[2];

			MonoAlphaSubstitution test(key);

			if (eord == "encrypt") {
				std::string encryptedText;
				for (char c : text) {
					encryptedText += test.encrypt(c);
				}
				std::cout << encryptedText << std::endl;
			}
			else if (eord == "decrypt") {
				std::string decryptedText;
				for (char c : text) {
					decryptedText += test.decrypt(c);
				}
				std::cout << decryptedText << std::endl;
			}
			else {
				std::cout << "The first parameter must be \"encrypt\" or \"decrypt\"!\nUsage: MonoAlphaSubstitution encrypt key \"cipher text\"" << std::endl;
			}
		}
	}

};

int main() {

	std::string key = "akbjcidhegffgehdicjbka";
	std::string text_to_encrypt = "Life is wasted on the egg living.";
	std::string encrypts = "encrypt";
	std::vector<std::string> values1 = { encrypts,key,text_to_encrypt };

	std::string text_to_decrypt = "Lcfe cs wasted on tde eee lcvcne.";
	std::string _decrypt = "decrypt";

	std::vector<std::string> values2 = { _decrypt,key,text_to_decrypt};

	MonoAlphaSubstitution mon;
	mon.processArgs(values1);

	std::cout << "\n";

	MonoAlphaSubstitution mon2;
	mon.processArgs(values2);


	return 0;

}



