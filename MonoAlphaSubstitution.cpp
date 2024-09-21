#include "MonoAlphaSubstitution.h"

int main() {
	int choice=1;

	do
	{
		std::string word;

		std::cout << "Please enter the text you wish to encrypt: ";
		std::getline(std::cin, word);

		MonoAlphaSubstitution substitution;


		// Encrypt a sample text
		std::string original_text = word;
		std::string encrypted_text;
		for (char c : original_text) {
			encrypted_text += substitution.encrypt(c);
		}

		// Decrypt the text
		std::string decrypted_text;
		for (char c : encrypted_text) {
			decrypted_text += substitution.decrypt(c);
		}
	
		//print out encrypted word 
		std::cout << "Word: " << word<<"\n";
		std::cout << "Encrypted: " << encrypted_text << "\n";

		//create file for saved encryption data
		storeEncryptedInfotoFile(word);
		
		
		choice = 0;


	} while (choice !=0);

	return 0;

}



