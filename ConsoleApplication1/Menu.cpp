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
        cout << "\n���� ������������ ������ �6:\n";
        cout << "1. �������� ������ � �������������� ����������\n";
        cout << "2. ������������ ��� ����� � �������\n";
        cout << "0. �����\n";
        cout << "�������� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            run_lab1();
            break;
        case 2:
            run_lab2();
            break;
        case 0:
            cout << "����� �� ���������.\n";
            break;
        default:
            cout << "������������ �����. ���������� �����.\n";
        }
    } while (choice != 0);
}

void run_lab1() {
    try {
        string password = get_password();
        cout << "������ ������: " << password << endl;
    }
    catch (const PasswordError& e) {
        cerr << "������ ������: " << e.what() << endl;
    }
    catch (const ExtraPasswordError& e) {
        cerr << "�������������� ������ ������: " << e.what() << endl;
    }
}


void run_lab2() {
    try {
        MainHero hero(0, 0, "����", 150);

        Weapon weapon1, weapon2;
        cout << "������� ������ ������:\n";
        cin >> weapon1;
        cout << "������� ������ ������:\n";
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
        cerr << "������� ������: " << e.what() << endl;
    }
}