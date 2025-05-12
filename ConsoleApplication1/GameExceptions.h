#pragma once
#include <stdexcept>

class GameError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class NoWeaponError : public GameError {
public:
    NoWeaponError() : GameError("������ ���������: � ��������� ��� ������") {}
};

class OverhealError : public GameError {
public:
    OverhealError() : GameError("������ �������� ���� ������������� ������ ��������") {}
};
