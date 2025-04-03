#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double w, double h) : width(w), height(h) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height must be positive.");
    }
}

double Rectangle::CalcArea() const {
    return width * height; // Площадь прямоугольника: ширина * высота
}

void Rectangle::Show() const {
    std::cout << "Rectangle: width = " << width << ", height = " << height
        << ", area = " << CalcArea() << std::endl;
}