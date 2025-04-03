#ifndef STUDENT_H
#define STUDENT_H

#include "Human.h"
#include <vector>

class Student : public Human {
private:
    std::vector<int> scores; // Вектор оценок

public:
    // Конструктор по умолчанию
    Student();

    // Конструктор с параметрами
    Student(const std::string& firstName, const std::string& lastName, const std::string& patronymic, const std::vector<int>& scores);

    // Метод для добавления оценки
    void addScore(int score);

    // Метод для вычисления среднего балла
    double getAverageScore() const;

    // Метод для получения краткой информации о студенте
    std::string getShortStudentInfo() const;

    // Метод для получения полной информации о студенте
    std::string getFullStudentInfo() const;
};

#endif // STUDENT_H