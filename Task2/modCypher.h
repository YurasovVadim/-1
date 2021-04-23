#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>
#include <string>
#include <map>
using namespace std;
class modCypher
{
    int key1;
public:
    modCypher()=delete;
    modCypher(const int& key) :key1(key) {}; 
    std::string encrypt(const std::string& open_text); 
    std::string decrypt(const std::string& cipher_text);
};