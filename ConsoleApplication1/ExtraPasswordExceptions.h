#pragma once
#include <stdexcept>

class ExtraPasswordError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class SpaceError : public ExtraPasswordError {
public:
    SpaceError() : ExtraPasswordError("������ �� ������ ��������� ��������") {}
};

class RepeatCharError : public ExtraPasswordError {
public:
    RepeatCharError() : ExtraPasswordError("������ �� ������ ��������� ������ ����� 3 ���������� ��������") {}
};
