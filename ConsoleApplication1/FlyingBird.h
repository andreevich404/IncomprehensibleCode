#ifndef FLYINGBIRD_H
#define FLYINGBIRD_H

#include "Bird.h"

class FlyingBird : public Bird {
public:
    void fly() const; // Специфический метод для полета
};

#endif // FLYINGBIRD_H