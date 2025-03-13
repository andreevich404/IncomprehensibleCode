#include "Menu.h"

// Конструктор
Menu::Menu() {}

// Метод для очистки консоли
void Menu::ClearConsole() {
#ifdef _WIN32
    system("cls"); // Для Windows
#else
    system("clear"); // Для Linux/MacOS
#endif
}

// Метод для отображения меню
void Menu::ShowMenu() {
    ClearConsole();
    std::cout << "Меню:" << std::endl;
    std::cout << "1. Задание 1 (Bell)" << std::endl;
    std::cout << "2. Задание 2 (OddEvenSeparator)" << std::endl;
    std::cout << "3. Задание 3 (Table)" << std::endl;
    std::cout << "4. Задание 4 (Complex)" << std::endl;
    std::cout << "5. Задание 5 (Stock)" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите задание: ";
}

// Метод для выполнения выбранного задания
void Menu::RunTask(int choice) {
    ClearConsole();
    switch (choice) {
    case 1:
        TaskBell();
        break;
    case 2:
        TaskOddEvenSeparator();
        break;
    case 3:
        TaskTable();
        break;
    case 4:
        TaskComplex();
        break;
    case 5:
        TaskStock();
        break;
    case 0:
        std::cout << "Выход из программы." << std::endl;
        break;
    default:
        std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        break;
    }
    if (choice != 0) {
        std::cout << "Нажмите Enter для продолжения...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}

// Метод для работы с классом Bell
void Menu::TaskBell() {
    std::cout << "Задание 1: Реализация класса Bell." << std::endl;
    std::cout << "Введите количество звуков: ";
    int count;
    std::cin >> count;

    if (count <= 0) {
        std::cerr << "Ошибка: количество звуков должно быть положительным числом." << std::endl;
        return;
    }

    Bell bell;
    for (int i = 0; i < count; ++i) {
        bell.sound();
    }
}

// Метод для работы с классом OddEvenSeparator
void Menu::TaskOddEvenSeparator() {
    std::cout << "Задание 2: Реализация класса OddEvenSeparator." << std::endl;
    std::cout << "Введите числа через пробел (для завершения ввода введите любой нечисловой символ): ";

    OddEvenSeparator separator;
    int number;
    while (std::cin >> number) {
        separator.add_number(number);
    }

    // Очистка потока ввода
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    separator.even();
    separator.odd();
}

// Метод для работы с классом Table
void Menu::TaskTable() {
    std::cout << "Задание 3: Реализация класса Table." << std::endl;
    std::cout << "Введите количество строк и столбцов: ";
    int rows, cols;
    std::cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cerr << "Ошибка: количество строк и столбцов должно быть положительным числом." << std::endl;
        return;
    }

    Table table(rows, cols);

    // Заполняем таблицу значениями
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            table.set_value(i, j, i * cols + j + 1); // Пример заполнения
        }
    }

    // Выводим таблицу
    std::cout << "Таблица:" << std::endl;
    table.print();

    // Выводим среднее арифметическое
    std::cout << "Среднее арифметическое: " << table.average() << std::endl;
}

// Метод для работы с классом Complex
void Menu::TaskComplex() {
    std::cout << "Задание 4: Реализация класса Complex." << std::endl;
    std::cout << "Введите действительную и мнимую части первого комплексного числа: ";
    double re1, im1;
    std::cin >> re1 >> im1;
    Complex z1(re1, im1);

    std::cout << "Введите действительную и мнимую части второго комплексного числа: ";
    double re2, im2;
    std::cin >> re2 >> im2;
    Complex z2(re2, im2);

    // Вывод чисел
    std::cout << "Первое число: ";
    z1.Print();
    std::cout << "Второе число: ";
    z2.Print();

    // Арифметические операции
    Complex sum = z1.Add(z2);
    std::cout << "Сумма: ";
    sum.Print();

    Complex diff = z1.Sub(z2);
    std::cout << "Разность: ";
    diff.Print();

    Complex prod = z1.Mult(z2);
    std::cout << "Произведение: ";
    prod.Print();

    Complex quot = z1.Div(z2);
    std::cout << "Частное: ";
    quot.Print();
}

// Метод для работы с классом Stock
void Menu::TaskStock() {
    std::cout << "Задание 5: Реализация класса Stock." << std::endl;
    Stock stock;

    // Добавляем коробки на склад
    stock.Add(10, 5);  // Коробка 0: вес=10, объем=5
    stock.Add(20, 3);  // Коробка 1: вес=20, объем=3
    stock.Add(15, 8);  // Коробка 2: вес=15, объем=8

    // Получаем коробку по минимальной грузоподъемности
    stock.GetByW(12);  // Должна быть выдана коробка 2 (вес=15)

    // Получаем коробку по минимальному объему
    stock.GetByV(4);   // Должна быть выдана коробка 0 (объем=5)
}