#include "OddEvenSeparator.h"

OddEvenSeparator::OddEvenSeparator() : numbers_count(0), evens_count(0), odds_count(0), capacity(10) {
    numbers = new int[capacity];
    evens = new int[capacity];
    odds = new int[capacity];
}

OddEvenSeparator::~OddEvenSeparator() {
    delete[] numbers;
    delete[] evens;
    delete[] odds;
}

// Метод для добавления числа
void OddEvenSeparator::add_number(int number) {
    numbers[numbers_count++] = number;

    if (number % 2 == 0) {
        evens[evens_count++] = number;
    }
    else {
        odds[odds_count++] = number;
    }
}

// Метод для вывода четных чисел
void OddEvenSeparator::even() const {
    std::cout << "Четные числа: ";
    for (int i = 0; i < evens_count; ++i) {
        std::cout << evens[i] << " ";
    }
    std::cout << std::endl;
}

// Метод для вывода нечетных чисел
void OddEvenSeparator::odd() const {
    std::cout << "Нечетные числа: ";
    for (int i = 0; i < odds_count; ++i) {
        std::cout << odds[i] << " ";
    }
    std::cout << std::endl;
}