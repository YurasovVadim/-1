#include "modCypher.h"

std::string modCypher::encrypt(const std::string& open_text)
{
    string n_s = open_text;
    int dl, nstrok, index, k;
    dl = open_text.length();
    nstrok = (dl - 1) / key1 + 1;
    k = 0;
    for (int i = key1; i > 0; i--) {
        for (int j = 0; j < nstrok; j++) {
            index = i+key1*j;
            if (index-1 < dl) {
                n_s[k] = open_text[index-1];
                k++;
            }
        }
    }
    return n_s;
}

std::string modCypher::decrypt(const std::string& cypher_text)
{
    string n_s = cypher_text;
    int dl, nstrok, index, k;
    dl = cypher_text.length();
    nstrok = (dl - 1) / key1 + 1;
    k = 0;
    for (int i = key1; i > 0; i--) {
        for (int j = 0; j < nstrok; j++) {
            index = i+key1*j;
            if (index-1 < dl) {
                n_s[index-1] = cypher_text[k];
                k++;
            }
        }
    }
    return n_s;
}
