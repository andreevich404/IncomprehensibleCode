#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
public:
    virtual void breathe() const = 0; // Виртуальный метод для дыхания
    virtual void eat() const = 0;     // Виртуальный метод для питания
    virtual ~Animal() {}              // Виртуальный деструктор
};

#endif // ANIMAL_H