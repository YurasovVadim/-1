#include "modCypher.h"

// проверка, чтобы строка состояла только из прописных букв
bool isValid(const string& s)
{
    for(const auto &c:s) // цикл проходит по всему массиву и выдает сам объект этого массива
        if (!isalpha(c) || !isupper(c) )
            return false;
    return true;
    
}

int main()
{
    
    int key;
    string text;
    unsigned operation_key;
    cout<<"Введенный ключ: ";
    cin>>key;
    if (!cin.good()) {
        cerr<<"Ключ не распознан\n";
        return 1;
    }
    cout<<"Ключ загружен\n";
    modCypher cypher(key);
    do {
        cout<<"Программа готова. Введите действие (0-выход, 1-зашифрование, 2-расшифрование): ";
        cin>>operation_key;
        if (operation_key > 2) {
            cout<<"Неопределенное действие\n";
        } else if (operation_key >0) {
            cout<<"Команда распознана. Введите текст: ";
            cin>>text;
            if (isValid(text)) {
                if (operation_key==1) {
                    cout<<"Зашифрованный текст: "<<cypher.encrypt(text)<<endl;
                } else {
                    cout<<"Расшифрованный текст: "<<cypher.decrypt(text)<<endl;
                }
            } else {
                cout<<"Действия прекращены. Нераспознаваемая строка\n";

            }
        }
    } while (operation_key!=0);

    return 0;
}
