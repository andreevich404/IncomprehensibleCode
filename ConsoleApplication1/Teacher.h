#ifndef TEACHER_H
#define TEACHER_H

#include "Human.h"
#include <vector>
#include <string>

enum class Position {
    Assistant,       // ���������
    SeniorLecturer,  // ������� �������������
    Docent,          // ������
    Professor        // ���������
};

class Teacher : public Human {
private:
    Position position; // ���������
    std::vector<std::string> subjects; // ������ ������������� ���������

public:
    // ����������� �� ���������
    Teacher();

    // ����������� � �����������
    Teacher(const std::string& firstName, const std::string& lastName, const std::string& patronymic, Position position, const std::vector<std::string>& subjects);

    // ����� ��� ���������� ��������
    void addSubject(const std::string& subject);

    // ����� ��� ��������� ������� ���������� � �������������
    std::string getShortTeacherInfo() const;

    // ����� ��� ��������� ������ ���������� � �������������
    std::string getFullTeacherInfo() const;
};

#endif // TEACHER_H