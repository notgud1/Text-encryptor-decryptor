#pragma once
#include "Cipher.h"

/*
This  is where we individual split a string into individual chars to either code/decode it and return the newly coded/decoded string 

the method of encryption/decryption has not yet been decided. However the methodology of each type is the same as we individually encode/decode a text char by char
*/


class Substitution :  Cipher
{
private:
	char encrypt(char c);
	char decrypt(char c);


	// func that returns an encrypted string 
	std::string& encrypt(std::string& plaintext) {

		std::string encrypted_string = ""; // string for the newly encrypted char to be put into 

		for (int i = 0; i < plaintext.size(); i++) {

			char position = plaintext[i];
			encrypted_string += encrypt(position);
		}

		return encrypted_string;
	}

	//func that returns a decrypted string
	std::string& decrypt(std::string& plaintext) {

		std::string decrypted_string = ""; // string for the newly decrypted char to be put into 

		for (int i = 0; i < plaintext.size(); i++) {

			char position = plaintext[i];
			decrypted_string += encrypt(position);
		}

		return decrypted_string;

	}


};

