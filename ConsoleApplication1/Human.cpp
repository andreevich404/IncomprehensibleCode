#include "Human.h"
#include <iostream>

// Конструктор по умолчанию
Human::Human() : firstName("Неизвестно"), lastName("Неизвестно"), patronymic("Неизвестно") {}

// Конструктор с параметрами
Human::Human(const std::string& firstName, const std::string& lastName, const std::string& patronymic)
    : firstName(firstName), lastName(lastName), patronymic(patronymic) {
}

// Метод для получения фамилии и инициалов
std::string Human::getSurnameAndInitials() const {
    std::string initials;
    if (!firstName.empty()) initials += firstName[0];
    if (!patronymic.empty()) initials += patronymic[0];
    return lastName + " " + initials;
}

// Метод для получения полного имени
std::string Human::getFullName() const {
    return lastName + " " + firstName + " " + patronymic;
}