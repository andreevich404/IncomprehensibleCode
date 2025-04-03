#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {
public:
    void breathe() const override; // ��������������� ������ breathe
    void eat() const override;     // ��������������� ������ eat
    void swim() const;             // ������������� ����� ��� ��������
};

#endif // FISH_H