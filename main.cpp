#include <iostream>
#include "modAlphaCipher.h"
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
    wstring key;
    wstring text;
    unsigned int op;
    wcout << L"Шифровальщик готов. Введите ключ: ";
    getline(wcin, key);
    try {
        modAlphaCipher cipher(key);
        wcout << L"Ключ установлен\n";
        do {
            wcout << L"Шифровальщик готов. Введите номер операции (0-выход, 1-зашифровать, 2-расшифровать): ";
            wcin >> op;
            if (op > 2) {
                wcerr << L"Неверный номер операции\n";
            } else if (op > 0) {
                wcout << L"Шифровальщик готов. Введите текст: ";
                wcin.ignore();
                getline(wcin, text);
                if (op == 1) {
                    wcout << cipher.encrypt(text) << endl;
                } else {
                    wcout << cipher.decrypt(text) << endl;
                }
            } 
            else if (op == 0) {return 0;}
            else {
                wcerr << L"Неверный формат текста\n";
            }
        } while (op != 0);
    } catch (const modAlphaCipher_error& e) {
        std::wcerr<<e.what()<<std::endl;
    }
    return 0;
}
