#ifndef ODDEVENSEPARATOR_H
#define ODDEVENSEPARATOR_H

#include <iostream>

class OddEvenSeparator {
private:
    int* numbers;  // Динамический массив для хранения всех чисел
    int* evens;    // Динамический массив для хранения четных чисел
    int* odds;     // Динамический массив для хранения нечетных чисел
    int numbers_count;  // Текущее количество чисел
    int evens_count;    // Текущее количество четных чисел
    int odds_count;     // Текущее количество нечетных чисел
    int capacity;       // Максимальная вместимость массивов

public:
    OddEvenSeparator();
    ~OddEvenSeparator();
    void add_number(int number);  // Метод для добавления числа
    void even() const;            // Метод для вывода четных чисел
    void odd() const;             // Метод для вывода нечетных чисел
};

#endif // ODDEVENSEPARATOR_H