#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
public:
    virtual void breathe() const = 0; // ����������� ����� ��� �������
    virtual void eat() const = 0;     // ����������� ����� ��� �������
    virtual ~Animal() {}              // ����������� ����������
};

#endif // ANIMAL_H