#include "MonoAlphaSubstitution.h"


#include "MonoAlphaSubstitution.h"
#include <iostream>
#include <string>
#include <fstream>

// Function to handle encryption
void encryptText() {
    std::string string_to_encrypt;
    std::string encrypted_text;
    MonoAlphaSubstitution substitution;

    std::cout << "Please enter the text you wish to encrypt: ";
    std::getline(std::cin, string_to_encrypt);  // Get the full line of input

    // Encrypt the word
    for (char c : string_to_encrypt) {
        encrypted_text += substitution.encrypt(c);
    }

    // Print out encrypted word
    std::cout << "Original: " << string_to_encrypt << "\n";
    std::cout << "Encrypted: " << encrypted_text << "\n";

    // Store the encrypted word and key in a file
    storeEncryptedInfotoFile(string_to_encrypt);
}

// Function to handle decryption
void decryptText() {
    std::string encrypted_text;
    std::string key;
    std::string decrypted_text;
    MonoAlphaSubstitution decryption;

    std::cout << "Please enter the text you wish to decrypt: ";
    std::getline(std::cin, encrypted_text); // Get the text to decrypt

    std::cout << "Please enter the key for decryption: ";
    std::getline(std::cin, key); // Get the decryption key

    // Set up decryption with the provided key
    decryption.decryptwithkey(key);

    // Decrypt the word
    for (char c : encrypted_text) {
        decrypted_text += decryption.decrypt(c);
    }

    // Print out decrypted text
    std::cout << "Decrypted: " << decrypted_text << "\n";
}

int main() {

    return 0;
}
