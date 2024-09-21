#pragma once
#include <iostream>
#include <string>
/*
//interface that declares methods that encrypty/decrypts text

 @author M M
*/

class Cipher
{
public:
	// encrypts a string of text 
	std::string& encrypt(const std::string plaintext);

	// decrypts a string of text
	std::string& decrypt(const std::string ciphertext);

};

