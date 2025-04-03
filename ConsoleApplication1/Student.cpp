#include "Student.h"
#include <numeric> // для std::accumulate

// Конструктор по умолчанию
Student::Student() : Human(), scores() {}

// Конструктор с параметрами
Student::Student(const std::string& firstName, const std::string& lastName, const std::string& patronymic, const std::vector<int>& scores)
    : Human(firstName, lastName, patronymic), scores(scores) {
}

// Метод для добавления оценки
void Student::addScore(int score) {
    scores.push_back(score);
}

// Метод для вычисления среднего балла
double Student::getAverageScore() const {
    if (scores.empty()) return 0.0;
    double sum = std::accumulate(scores.begin(), scores.end(), 0);
    return sum / scores.size();
}

// Метод для получения краткой информации о студенте
std::string Student::getShortStudentInfo() const {
    return getSurnameAndInitials() + ": " + std::to_string(getAverageScore());
}

// Метод для получения полной информации о студенте
std::string Student::getFullStudentInfo() const {
    std::string result = getFullName() + ": ";
    for (int score : scores) {
        result += std::to_string(score) + " ";
    }
    result += "-- " + std::to_string(getAverageScore());
    return result;
}