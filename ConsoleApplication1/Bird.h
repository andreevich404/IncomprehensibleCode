#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    void breathe() const override; // ��������������� ������ breathe
    void eat() const override;     // ��������������� ������ eat
    void lay_eggs() const;         // ������������� ����� ��� ������������ ���
};

#endif // BIRD_H