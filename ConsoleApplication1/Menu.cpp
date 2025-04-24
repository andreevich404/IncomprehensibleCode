#include "stdafx.h"
#include "Menu.h"
#include "Contains.h"
#include "Change.h"
#include "Matrix.h"
#include "Polynomial.h"
#include <limits>
#include <cstdlib> // Для system()

using namespace std;

void LabMenu::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void LabMenu::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

template <typename T>
T LabMenu::getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            clearInput();
            cout << "Ошибка ввода. Пожалуйста, введите корректное значение.\n";
        }
        else {
            clearInput();
            return value;
        }
    }
}

void LabMenu::showMainMenu() {
    clearScreen();
    cout << "\n=== Лабораторная работа 5: ООП на С++ - шаблоны ===\n";
    cout << "1. Задание 1: Шаблонная функция contains\n";
    cout << "2. Задание 2: Шаблонная функция change\n";
    cout << "3. Задание 3: Шаблонный класс Matrix\n";
    cout << "4. Задание 4: Шаблонный класс Polynomial\n";
    cout << "0. Выход\n";
    cout << "Выберите задание: ";
}

void LabMenu::run() {
    while (true) {
        showMainMenu();
        int choice = getInput<int>("");

        switch (choice) {
        case 1:
            clearScreen();
            demoContains();
            cout << "\nНажмите Enter для продолжения...";
            clearInput();
            break;
        case 2:
            clearScreen();
            demoChange();
            cout << "\nНажмите Enter для продолжения...";
            clearInput();
            break;
        case 3:
            clearScreen();
            demoMatrix();
            cout << "\nНажмите Enter для продолжения...";
            clearInput();
            break;
        case 4:
            clearScreen();
            demoPolynomial();
            cout << "\nНажмите Enter для продолжения...";
            clearInput();
            break;
        case 0:
            return;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            clearInput();
        }
    }
}

// Явные инстанциации шаблонного метода
template int LabMenu::getInput<int>(const string&);
template double LabMenu::getInput<double>(const string&);
template string LabMenu::getInput<string>(const string&);