#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
public:
    virtual double CalcArea() const = 0; // Виртуальный метод для вычисления площади
    virtual void Show() const = 0;      // Виртуальный метод для вывода информации о фигуре
    virtual ~Figure() {}                // Виртуальный деструктор
};

#endif // FIGURE_H