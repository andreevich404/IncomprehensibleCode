#ifndef TEACHER_H
#define TEACHER_H

#include "Human.h"
#include <vector>
#include <string>

enum class Position {
    Assistant,       // Ассистент
    SeniorLecturer,  // Старший преподаватель
    Docent,          // Доцент
    Professor        // Профессор
};

class Teacher : public Human {
private:
    Position position; // Должность
    std::vector<std::string> subjects; // Список преподаваемых предметов

public:
    // Конструктор по умолчанию
    Teacher();

    // Конструктор с параметрами
    Teacher(const std::string& firstName, const std::string& lastName, const std::string& patronymic, Position position, const std::vector<std::string>& subjects);

    // Метод для добавления предмета
    void addSubject(const std::string& subject);

    // Метод для получения краткой информации о преподавателе
    std::string getShortTeacherInfo() const;

    // Метод для получения полной информации о преподавателе
    std::string getFullTeacherInfo() const;
};

#endif // TEACHER_H