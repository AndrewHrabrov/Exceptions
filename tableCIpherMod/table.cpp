#include "table.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

tableCipher::tableCipher(unsigned int columns) : columns(getValidKey(columns)) {}

std::wstring tableCipher::encrypt(const std::wstring& sourcetext) {
    unsigned int rows = (sourcetext.length() + columns - 1) / columns; 
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(columns, ' ')); 

    for (size_t i = 0; i < sourcetext.length(); ++i) {
        table[i / columns][i % columns] = sourcetext[i];
    }
    
    std::wstring ciphertext;

    for (int column = columns - 1; column >= 0; --column) {
        for (unsigned int row = 0; row < rows; ++row) {
            ciphertext += table[row][column];
        }
    }
    return ciphertext;
}

std::wstring tableCipher::decrypt(const std::wstring& ciphertext) {
    unsigned int rows = (ciphertext.length() + columns - 1) / columns; 
    std::vector<std::vector<wchar_t>> table(rows, std::vector<wchar_t>(columns, ' ')); 

    size_t i = 0;
    for (int column = columns - 1; column >= 0; --column) {
        for (unsigned int row = 0; row < rows; ++row) {
            if (i < ciphertext.length()) {
                table[row][column] = ciphertext[i++];
            }
        }
    }
    std::wstring sourcetext;
    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int column = 0; column < columns; ++column) {
            sourcetext += table[row][column];
        }
    }
    

    return sourcetext;
}

unsigned int tableCipher::getValidKey(unsigned int s)
{
    if (std::to_string(s).empty()) {
        throw tableCipher_error("Empty key");
    }
    if (s > 100 || s <= 0) {
        throw tableCipher_error(std::string("Invalid key "));
    }
    return s;
}

std::wstring tableCipher::getValidText(const std::wstring& text)
{
    if (text.empty()) {
        throw tableCipher_error("Empty text");
    }
    return text;
}


