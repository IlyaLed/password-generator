#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

string generatePassword(int length, bool useDigits, bool useSymbols) {
    const string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    string chars = letters;
    if (useDigits) chars += digits;
    if (useSymbols) chars += symbols;

    srand(time(0));
    string password;
    for (int i = 0; i < length; ++i) {
        password += chars[rand() % chars.size()];
    }
    return password;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int length;
    bool digits, symbols;

    if (length < 6) {
        cout << "Пароль должен быть не короче 6 символов!" << endl;
        return 1;
    }
    cout << "Длина пароля: ";
    cin >> length;
    cout << "Цифры (1/0): ";
    cin >> digits;
    cout << "Спецсимволы (1/0): ";
    cin >> symbols;

    string password = generatePassword(length, digits, symbols);
    cout << "Ваш пароль: " << password << endl;

    return 0;
}