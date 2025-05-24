/**
 * @file password.cpp
 * @brief Генератор случайных паролей
 * @author Леднев Илья Алексеевич
 * @date 2023
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <clocale>
//проверка CI/CD
using namespace std;

/*ИЗМЕНЕНИЕ*/

/**
 * @brief Генерирует случайный пароль
 * @param length Длина пароля
 * @param useDigits Использовать цифры
 * @param useSymbols Использовать спецсимволы
 * @return Сгенерированный пароль
 */
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

/**
 * @brief Основная функция программы
 * @return Код завершения (0 - успех, 1 - ошибка)
 */

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int length;
    bool digits, symbols;

    cout << "Длина пароля: "; 
    cin >> length;
    
    if (length < 6) {
        cout << "Пароль должен быть не короче 6 символов!" << endl;
        return 1;
    }
    
    cout << "Цифры (1/0): ";
    cin >> digits;
    cout << "Спецсимволы (1/0): ";
    cin >> symbols;

    string password = generatePassword(length, digits, symbols);
    cout << "Ваш пароль: " << password << endl;

    return 0;
}