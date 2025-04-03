#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    void breathe() const override; // Переопределение метода breathe
    void eat() const override;     // Переопределение метода eat
    void lay_eggs() const;         // Специфический метод для откладывания яиц
};

#endif // BIRD_H