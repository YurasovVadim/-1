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
class modAlphaCypher
{
private:
    std::string numAlpha =
        "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
    std::map <char,int> alphaNum; //ассоциативный массив "номер по символу"
    std::vector <int> key; //ключ
    std::vector<int> convert(const std::string& s); //преобразование строка-вектор
    std::string convert(const std::vector<int>& v); //преобразование вектор-строка
public:
    modAlphaCypher()=delete; //запретим конструктор без параметров
    modAlphaCypher(const std::string& skey); //конструктор для установки ключа
    std::string encrypt(const std::string& open_text); //зашифрование
    std::string decrypt(const std::string& cipher_text);//расшифрование
};
