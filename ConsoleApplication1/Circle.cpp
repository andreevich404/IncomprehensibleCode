#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"
#include <iostream>
#include <stdexcept>

Circle::Circle(double r) : radius(r) {
    if (radius <= 0) {
        throw std::invalid_argument("Radius must be positive.");
    }
}

double Circle::CalcArea() const {
    return M_PI * radius * radius;
}

void Circle::Show() const {
    std::cout << "Circle: radius = " << radius << ", area = " << CalcArea() << std::endl;
}