#include "modAlphaCypher.h"
// проверка, чтобы строка состояла только из прописных букв
bool isValid(const string& s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec; 
    std::wstring ws = codec.from_bytes(s); 
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::wstring wA = codec.from_bytes(numAlpha);
    for(int i = 0; i < ws.size(); i++) {
        if (wA.find(ws[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
int main()
{
    string key;
    string text;
    unsigned operation_key;
    cout<<"Введите ключ: ";
    cin>>key;
    if (!isValid(key)) {
        cout<<"Ключ не распознан\n";
        return 1;
    }
    cout<<"Ключ загружен\n";
    modAlphaCypher cypher(key);
    do {
        cout<<"Введите действие (0-выход, 1-зашифрование, 2-расшифрование): ";
        cin>>operation_key;
        if (operation_key > 2) {
            cout<<"Нераспознанная операция\n";
        } else if (operation_key >0) {
            cout<<"Команда распознана. Введите текст: ";
            cin>>text;
            if (isValid(text)) {
                if (operation_key==1) {
                    cout<<"Зашифрованное сообщение: "<<cypher.encrypt(text)<<endl;
                } else {
                    cout<<"Расшифрованное сообщение: "<<cypher.decrypt(text)<<endl;
                }
            } else {
                cout<<"Действие отменено. Нераспознанный текст\n";

            }
        }
    } while (operation_key!=0);
    return 0;
}