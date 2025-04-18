﻿/*
==================================================
Лабораторная работа №4 по курсу "Языки программирования"
Тема: ООП на С++: переопределение операторов
==================================================

Спецификация программы:

Выполнил: Толкачев Иван Андреевич
Группа: ФИТ-241

Программа демонстрирует переопределение операторов в С++:
1. Класс Complex для работы с комплексными числами
2. Класс Rational для работы с рациональными числами
3. Полную перегрузку арифметических и логических операторов
4. Реализацию операторов ввода/вывода

Входные данные:
- Для Complex: действительная и мнимая части комплексных чисел
- Для Rational: числитель и знаменатель рациональных чисел
- Выбор задания через интерактивное меню

Выходные данные:
- Результаты арифметических операций с числами
- Результаты сравнения чисел
- Информация о работе операторов инкремента/декремента

Используемые файлы:
- Complex.h, Complex.cpp - реализация комплексных чисел
- Rational.h, Rational.cpp - реализация рациональных чисел
- Menu.h, Menu.cpp - система интерактивного меню
- main.cpp - точка входа в программу

Результат работы:
Программа предоставляет интерактивное меню для тестирования
функциональности классов Complex и Rational, демонстрируя
корректную работу всех перегруженных операторов.
==================================================
*/

#include <iostream>
#include "Menu.h"

int main() {
    setlocale(LC_ALL, "");
    showMenu();
    return 0;
}