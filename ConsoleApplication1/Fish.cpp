#include "Fish.h"
#include <iostream>

void Fish::breathe() const {
    std::cout << "The fish is breathing underwater." << std::endl;
}

void Fish::eat() const {
    std::cout << "The fish is eating plankton." << std::endl;
}

void Fish::swim() const {
    std::cout << "The fish is swimming." << std::endl;
}