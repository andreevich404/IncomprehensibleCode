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

// Инициализация меню с заданиями
void Menu::initialize() {
    // Добавляем все задания в меню
    addItem("1. Геометрические фигуры", [this]() { task1(); });
    addItem("2. Иерархия животных", [this]() { task2(); });
    addItem("3. Студенты и преподаватели", [this]() { task3(); });
    addItem("4. Сумматоры последовательностей", [this]() { task4(); });
}

// Добавление пункта в меню
void Menu::addItem(const string& name, function<void()> action) {
    MenuItem item;
    item.name = name;
    item.action = action;
    items.push_back(item);
}

// Запуск меню
void Menu::run() {
    while (true) {
        cout << "\n=== Главное меню ===" << endl;

        // Выводим все пункты меню
        for (size_t i = 0; i < items.size(); i++) {
            cout << items[i].name << endl;
        }
        cout << "0. Выход" << endl;

        int choice;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) {
            break; // Выход из программы
        }

        // Проверяем правильность выбора
        if (choice > 0 && choice <= (int)items.size()) {
            items[choice - 1].action(); // Запускаем выбранное задание
        }
        else {
            cout << "Ошибка! Попробуйте снова." << endl;
        }
    }
}

// Задание 1: Геометрические фигуры
void Menu::task1() {
    while (true) {
        cout << "\n=== Геометрические фигуры ===" << endl;
        cout << "1. Круг" << endl;
        cout << "2. Прямоугольник" << endl;
        cout << "0. Назад" << endl;

        int choice;
        cout << "Выберите фигуру: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: task1_circle(); break;
        case 2: task1_rectangle(); break;
        default: cout << "Ошибка выбора!" << endl;
        }
    }
}

void Menu::task1_circle() {
    cout << "\n--- Круг ---" << endl;
    double radius;
    cout << "Введите радиус: ";
    cin >> radius;

    Circle circle(radius);
    circle.Show();

    double height;
    cout << "Введите высоту цилиндра: ";
    cin >> height;

    double volume = circle.CalcArea() * height;
    cout << "Объем цилиндра: " << volume << endl;
}

void Menu::task1_rectangle() {
    cout << "\n--- Прямоугольник ---" << endl;
    double width, height;
    cout << "Введите ширину: ";
    cin >> width;
    cout << "Введите высоту: ";
    cin >> height;

    Rectangle rect(width, height);
    rect.Show();

    double cylinderHeight;
    cout << "Введите высоту цилиндра: ";
    cin >> cylinderHeight;

    double volume = rect.CalcArea() * cylinderHeight;
    cout << "Объем цилиндра: " << volume << endl;
}

// Задание 2: Иерархия животных
void Menu::task2() {
    while (true) {
        cout << "\n=== Иерархия животных ===" << endl;
        cout << "1. Раннее связывание" << endl;
        cout << "2. Позднее связывание" << endl;
        cout << "0. Назад" << endl;

        int choice;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: task2_early_binding(); break;
        case 2: task2_late_binding(); break;
        default: cout << "Ошибка выбора!" << endl;
        }
    }
}

void Menu::task2_early_binding() {
    cout << "\n--- Раннее связывание ---" << endl;

    Fish fish;
    Bird bird;
    FlyingBird flyingBird;

    cout << "Рыба:" << endl;
    fish.breathe();
    fish.eat();
    fish.swim();

    cout << "\nПтица:" << endl;
    bird.breathe();
    bird.eat();
    bird.lay_eggs();

    cout << "\nЛетающая птица:" << endl;
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();
}

void Menu::task2_late_binding() {
    cout << "\n--- Позднее связывание ---" << endl;

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

// Задание 3: Студенты и преподаватели
void Menu::task3() {
    cout << "\n=== Студенты и преподаватели ===" << endl;

    // Создаем студентов
    Student student1("Иван", "Иванов", "Иванович", { 4, 5, 3 });
    Student student2("Петр", "Петров", "Петрович", { 5, 5, 5 });

    // Создаем преподавателей
    Teacher teacher1("Алексей", "Алексеев", "Алексеевич", Position::Docent, { "Математика" });
    Teacher teacher2("Борис", "Борисов", "Борисович", Position::Professor, { "Информатика", "Программирование" });

    // Выводим информацию
    cout << "\nСтуденты:" << endl;
    cout << student1.getShortStudentInfo() << endl;
    cout << student2.getFullStudentInfo() << endl;

    cout << "\nПреподаватели:" << endl;
    cout << teacher1.getShortTeacherInfo() << endl;
    cout << teacher2.getFullTeacherInfo() << endl;
}

// Задание 4: Сумматоры последовательностей
void Menu::task4() {
    cout << "\n=== Сумматоры последовательностей ===" << endl;

    int N;
    cout << "Введите число N: ";
    cin >> N;

    Summator basic;
    SquareSummator squares;
    CubeSummator cubes;

    cout << "Сумма чисел: " << basic.sum(N) << endl;
    cout << "Сумма квадратов: " << squares.sum(N) << endl;
    cout << "Сумма кубов: " << cubes.sum(N) << endl;
}