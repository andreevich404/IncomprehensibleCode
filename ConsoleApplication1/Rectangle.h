#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
private:
    double width;  // Ширина прямоугольника
    double height; // Высота прямоугольника

public:
    Rectangle(double w, double h); // Конструктор
    double CalcArea() const override; // Переопределение метода CalcArea
    void Show() const override;       // Переопределение метода Show
};

#endif // RECTANGLE_H