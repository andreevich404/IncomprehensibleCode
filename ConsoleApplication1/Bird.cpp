#include "Bird.h"
#include <iostream>

void Bird::breathe() const {
    std::cout << "The bird is breathing air." << std::endl;
}

void Bird::eat() const {
    std::cout << "The bird is eating seeds." << std::endl;
}

void Bird::lay_eggs() const {
    std::cout << "The bird is laying eggs." << std::endl;
}