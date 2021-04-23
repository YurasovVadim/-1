#include "modAlphaCypher.h"

modAlphaCypher::modAlphaCypher(const std::string& skey)
{
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha); // перекодируем
    for (unsigned i=0; i<ws.size(); i++) {
        alphaNum[ws[i]]=i;
    }
    key = convert(skey);
}

std::string modAlphaCypher::encrypt(const std::string& open_text)
{
    std::vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

std::string modAlphaCypher::decrypt(const std::string& cypher_text)
{
    std::vector<int> work = convert(cypher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

inline std::vector<int> modAlphaCypher::convert(const std::string& s)
{
    std::vector<int> res;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(s); // перекодируем
    for (unsigned i=0; i<ws.size(); i++) {
        res.push_back(alphaNum[ws[i]]);
    }
    return res;
}

inline std::string modAlphaCypher::convert(const std::vector<int>& v)
{
    std::string res;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha);
    wstring res_s = codec.from_bytes("");
    for (unsigned i=0; i<v.size(); i++) {
        res_s.push_back(ws[v[i]]);
    }
    res = codec.to_bytes(res_s);
    return res;
}