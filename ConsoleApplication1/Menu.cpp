#include "Menu.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "Circle.h"
#include "Rectangle.h"
#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"
#include "Student.h"
#include "Teacher.h"
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"

using namespace std;

// ������������� ���� � ���������
void Menu::initialize() {
    // ��������� ��� ������� � ����
    addItem("1. �������������� ������", [this]() { task1(); });
    addItem("2. �������� ��������", [this]() { task2(); });
    addItem("3. �������� � �������������", [this]() { task3(); });
    addItem("4. ��������� �������������������", [this]() { task4(); });
}

// ���������� ������ � ����
void Menu::addItem(const string& name, function<void()> action) {
    MenuItem item;
    item.name = name;
    item.action = action;
    items.push_back(item);
}

// ������ ����
void Menu::run() {
    while (true) {
        cout << "\n=== ������� ���� ===" << endl;

        // ������� ��� ������ ����
        for (size_t i = 0; i < items.size(); i++) {
            cout << items[i].name << endl;
        }
        cout << "0. �����" << endl;

        int choice;
        cout << "��� �����: ";
        cin >> choice;

        if (choice == 0) {
            break; // ����� �� ���������
        }

        // ��������� ������������ ������
        if (choice > 0 && choice <= (int)items.size()) {
            items[choice - 1].action(); // ��������� ��������� �������
        }
        else {
            cout << "������! ���������� �����." << endl;
        }
    }
}

// ������� 1: �������������� ������
void Menu::task1() {
    while (true) {
        cout << "\n=== �������������� ������ ===" << endl;
        cout << "1. ����" << endl;
        cout << "2. �������������" << endl;
        cout << "0. �����" << endl;

        int choice;
        cout << "�������� ������: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: task1_circle(); break;
        case 2: task1_rectangle(); break;
        default: cout << "������ ������!" << endl;
        }
    }
}

void Menu::task1_circle() {
    cout << "\n--- ���� ---" << endl;
    double radius;
    cout << "������� ������: ";
    cin >> radius;

    Circle circle(radius);
    circle.Show();

    double height;
    cout << "������� ������ ��������: ";
    cin >> height;

    double volume = circle.CalcArea() * height;
    cout << "����� ��������: " << volume << endl;
}

void Menu::task1_rectangle() {
    cout << "\n--- ������������� ---" << endl;
    double width, height;
    cout << "������� ������: ";
    cin >> width;
    cout << "������� ������: ";
    cin >> height;

    Rectangle rect(width, height);
    rect.Show();

    double cylinderHeight;
    cout << "������� ������ ��������: ";
    cin >> cylinderHeight;

    double volume = rect.CalcArea() * cylinderHeight;
    cout << "����� ��������: " << volume << endl;
}

// ������� 2: �������� ��������
void Menu::task2() {
    while (true) {
        cout << "\n=== �������� �������� ===" << endl;
        cout << "1. ������ ����������" << endl;
        cout << "2. ������� ����������" << endl;
        cout << "0. �����" << endl;

        int choice;
        cout << "��� �����: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: task2_early_binding(); break;
        case 2: task2_late_binding(); break;
        default: cout << "������ ������!" << endl;
        }
    }
}

void Menu::task2_early_binding() {
    cout << "\n--- ������ ���������� ---" << endl;

    Fish fish;
    Bird bird;
    FlyingBird flyingBird;

    cout << "����:" << endl;
    fish.breathe();
    fish.eat();
    fish.swim();

    cout << "\n�����:" << endl;
    bird.breathe();
    bird.eat();
    bird.lay_eggs();

    cout << "\n�������� �����:" << endl;
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();
}

void Menu::task2_late_binding() {
    cout << "\n--- ������� ���������� ---" << endl;

    Animal* animals[3];
    animals[0] = new Fish();
    animals[1] = new Bird();
    animals[2] = new FlyingBird();

    for (int i = 0; i < 3; i++) {
        animals[i]->breathe();
        animals[i]->eat();
        delete animals[i];
    }
}

// ������� 3: �������� � �������������
void Menu::task3() {
    cout << "\n=== �������� � ������������� ===" << endl;

    // ������� ���������
    Student student1("����", "������", "��������", { 4, 5, 3 });
    Student student2("����", "������", "��������", { 5, 5, 5 });

    // ������� ��������������
    Teacher teacher1("�������", "��������", "����������", Position::Docent, { "����������" });
    Teacher teacher2("�����", "�������", "���������", Position::Professor, { "�����������", "����������������" });

    // ������� ����������
    cout << "\n��������:" << endl;
    cout << student1.getShortStudentInfo() << endl;
    cout << student2.getFullStudentInfo() << endl;

    cout << "\n�������������:" << endl;
    cout << teacher1.getShortTeacherInfo() << endl;
    cout << teacher2.getFullTeacherInfo() << endl;
}

// ������� 4: ��������� �������������������
void Menu::task4() {
    cout << "\n=== ��������� ������������������� ===" << endl;

    int N;
    cout << "������� ����� N: ";
    cin >> N;

    Summator basic;
    SquareSummator squares;
    CubeSummator cubes;

    cout << "����� �����: " << basic.sum(N) << endl;
    cout << "����� ���������: " << squares.sum(N) << endl;
    cout << "����� �����: " << cubes.sum(N) << endl;
}