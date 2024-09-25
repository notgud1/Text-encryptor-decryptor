#include "Cipher.h"
#include "Substitution.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // For std::shuffle
#include <random>    // For std::random_device and std::mt19937
#include <fstream>

class Vigenere : Cipher
{
    std::unordered_map<char,char> map;
    std::vector<int> ciphers;
    int pos=0;



public:
    Vigenere(std::string key){

        


    }







};