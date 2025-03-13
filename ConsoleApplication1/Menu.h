#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <limits>
#include "Bell.h"
#include "OddEvenSeparator.h"
#include "Table.h"
#include "Complex.h"
#include "Stock.h"

class Menu {
public:
    Menu();  // Конструктор

    void ShowMenu(); // Метод для отображения меню
    void RunTask(int choice); // Метод для выполнения выбранного задания

private:
    void ClearConsole(); // Метод для очистки консоли
    void TaskBell();     // Метод для работы с классом Bell
    void TaskOddEvenSeparator(); // Метод для работы с классом OddEvenSeparator
    void TaskTable();    // Метод для работы с классом Table
    void TaskComplex();  // Метод для работы с классом Complex
    void TaskStock();    // Метод для работы с классом Stock
};

#endif // MENU_H