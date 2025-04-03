#include "Teacher.h"
#include <iostream>

// Конструктор по умолчанию
Teacher::Teacher() : Human(), position(Position::Assistant), subjects() {}

// Конструктор с параметрами
Teacher::Teacher(const std::string& firstName, const std::string& lastName, const std::string& patronymic, Position position, const std::vector<std::string>& subjects)
    : Human(firstName, lastName, patronymic), position(position), subjects(subjects) {
}

// Метод для добавления предмета
void Teacher::addSubject(const std::string& subject) {
    subjects.push_back(subject);
}

// Метод для получения краткой информации о преподавателе
std::string Teacher::getShortTeacherInfo() const {
    std::string positionStr;
    switch (position) {
    case Position::Assistant: positionStr = "ассистент"; break;
    case Position::SeniorLecturer: positionStr = "старший преподаватель"; break;
    case Position::Docent: positionStr = "доцент"; break;
    case Position::Professor: positionStr = "профессор"; break;
    }
    return getSurnameAndInitials() + " " + positionStr + ": " + std::to_string(subjects.size());
}

// Метод для получения полной информации о преподавателе
std::string Teacher::getFullTeacherInfo() const {
    std::string positionStr;
    switch (position) {
    case Position::Assistant: positionStr = "ассистент"; break;
    case Position::SeniorLecturer: positionStr = "старший преподаватель"; break;
    case Position::Docent: positionStr = "доцент"; break;
    case Position::Professor: positionStr = "профессор"; break;
    }
    std::string result = getFullName() + " " + positionStr + ": ";
    for (const std::string& subject : subjects) {
        result += subject + ", ";
    }
    if (!subjects.empty()) {
        result.pop_back(); // Убираем последнюю запятую
        result.pop_back(); // Убираем пробел
    }
    return result;
}