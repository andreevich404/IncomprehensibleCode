#include "Teacher.h"
#include <iostream>

// ����������� �� ���������
Teacher::Teacher() : Human(), position(Position::Assistant), subjects() {}

// ����������� � �����������
Teacher::Teacher(const std::string& firstName, const std::string& lastName, const std::string& patronymic, Position position, const std::vector<std::string>& subjects)
    : Human(firstName, lastName, patronymic), position(position), subjects(subjects) {
}

// ����� ��� ���������� ��������
void Teacher::addSubject(const std::string& subject) {
    subjects.push_back(subject);
}

// ����� ��� ��������� ������� ���������� � �������������
std::string Teacher::getShortTeacherInfo() const {
    std::string positionStr;
    switch (position) {
    case Position::Assistant: positionStr = "���������"; break;
    case Position::SeniorLecturer: positionStr = "������� �������������"; break;
    case Position::Docent: positionStr = "������"; break;
    case Position::Professor: positionStr = "���������"; break;
    }
    return getSurnameAndInitials() + " " + positionStr + ": " + std::to_string(subjects.size());
}

// ����� ��� ��������� ������ ���������� � �������������
std::string Teacher::getFullTeacherInfo() const {
    std::string positionStr;
    switch (position) {
    case Position::Assistant: positionStr = "���������"; break;
    case Position::SeniorLecturer: positionStr = "������� �������������"; break;
    case Position::Docent: positionStr = "������"; break;
    case Position::Professor: positionStr = "���������"; break;
    }
    std::string result = getFullName() + " " + positionStr + ": ";
    for (const std::string& subject : subjects) {
        result += subject + ", ";
    }
    if (!subjects.empty()) {
        result.pop_back(); // ������� ��������� �������
        result.pop_back(); // ������� ������
    }
    return result;
}