#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human {
protected:
    std::string firstName;  // Имя
    std::string lastName;   // Фамилия
    std::string patronymic; // Отчество

public:
    // Конструктор по умолчанию
    Human();

    // Конструктор с параметрами
    Human(const std::string& firstName, const std::string& lastName, const std::string& patronymic);

    // Метод для получения фамилии и инициалов
    std::string getSurnameAndInitials() const;

    // Метод для получения полного имени
    std::string getFullName() const;

    // Виртуальный деструктор
    virtual ~Human() {}
};

#endif // HUMAN_H