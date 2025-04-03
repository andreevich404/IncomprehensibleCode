#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {
public:
    void breathe() const override; // Переопределение метода breathe
    void eat() const override;     // Переопределение метода eat
    void swim() const;             // Специфический метод для плавания
};

#endif // FISH_H