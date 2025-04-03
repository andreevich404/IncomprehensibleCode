#include "Human.h"
#include <iostream>

// ����������� �� ���������
Human::Human() : firstName("����������"), lastName("����������"), patronymic("����������") {}

// ����������� � �����������
Human::Human(const std::string& firstName, const std::string& lastName, const std::string& patronymic)
    : firstName(firstName), lastName(lastName), patronymic(patronymic) {
}

// ����� ��� ��������� ������� � ���������
std::string Human::getSurnameAndInitials() const {
    std::string initials;
    if (!firstName.empty()) initials += firstName[0];
    if (!patronymic.empty()) initials += patronymic[0];
    return lastName + " " + initials;
}

// ����� ��� ��������� ������� �����
std::string Human::getFullName() const {
    return lastName + " " + firstName + " " + patronymic;
}