#include <iostream>
#include "table.h"
#include <locale.h>
#include <stdexcept>
#include <sstream>
using namespace std;

int main() {
    try {
        setlocale(LC_ALL, "");
        wstring text = L"";
        wstring ciphertext = L"";
        int columns;
        wstring col = L"";
        unsigned int op;
        wcout << L"Введите количество столбцов: ";
        getline(wcin, col);
        
        columns = stoi(col);
        tableCipher cipher(columns);
        wcout << L"Ключ установлен\n";
        do {
            wcout << L"Введите номер операции (0-выход, 1-зашифровать, 2-расшифровать): ";
            wcin >> op;
            if (op > 2) {wcerr << L"Неверный номер операции\n";}
            else if (op == 1) {
                wcout << L"Введите текст: ";
                wcin.ignore();
                getline(wcin, text);
                cipher.getValidText(text);
                wstring ciphertext = cipher.encrypt(text);
                wcout << L"Зашифрованный текст: " << ciphertext << endl;
            }
            else if (op == 2) {
                wcout << L"Введите зашифрованный текст: ";
                wcin.ignore();
                getline(wcin, ciphertext);
                cipher.getValidText(ciphertext);
                wstring decryptedText = cipher.decrypt(ciphertext);
                wcout << L"Расшифрованный текст: " << decryptedText << endl;
            }
        } while (op != 0);
    } catch(const tableCipher_error& e) {
        std::wcerr<<e.what()<<std::endl;
    }
    catch (const std::exception& e) {
        std::wcerr << L"Ошибка: Введена пустая строка!" << std::endl;
    }
    return 0;
}
