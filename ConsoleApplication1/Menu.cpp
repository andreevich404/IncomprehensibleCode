#include "Menu.h"
#include "Password.h"
#include "MainHero.h"
#include "BaseEnemy.h"
#include "Weapon.h"
#include "ExtraPasswordExceptions.h"
#include "GameExceptions.h"
#include <iostream>

using namespace std;

void show_menu() {
    int choice;
    do {
        cout << "\nМеню лабораторной работы №6:\n";
        cout << "1. Проверка пароля с использованием исключений\n";
        cout << "2. Демонстрация боя героя с врагами\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1:
            run_lab1();
            break;
        case 2:
            run_lab2();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

void run_lab1() {
    try {
        string password = get_password();
        cout << "Пароль принят: " << password << endl;
    }
    catch (const PasswordError& e) {
        cerr << "Ошибка пароля: " << e.what() << endl;
    }
    catch (const ExtraPasswordError& e) {
        cerr << "Дополнительная ошибка пароля: " << e.what() << endl;
    }
}


void run_lab2() {
    try {
        MainHero hero(0, 0, "Иван", 150);

        Weapon weapon1, weapon2;
        cout << "Введите первое оружие:\n";
        cin >> weapon1;
        cout << "Введите второе оружие:\n";
        cin >> weapon2;

        hero.add_weapon(weapon1);
        hero.add_weapon(weapon2);

        BaseEnemy enemy1(5, 5, weapon1, 60);
        BaseEnemy enemy2(10, 10, weapon2, 80);

        cout << enemy1 << endl;
        cout << enemy2 << endl;

        hero.hit(enemy1);
        hero.move(5, 5);
        hero.hit(enemy1);

        hero.next_weapon();
        hero.hit(enemy2);

        hero.heal(40);
    }
    catch (const GameError& e) {
        cerr << "Игровая ошибка: " << e.what() << endl;
    }
}