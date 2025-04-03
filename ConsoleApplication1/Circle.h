#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure {
private:
    double radius; // Радиус круга

public:
    Circle(double r); // Конструктор
    double CalcArea() const override; // Переопределение метода CalcArea
    void Show() const override;       // Переопределение метода Show
};

#endif // CIRCLE_H