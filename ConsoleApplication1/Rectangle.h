#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
private:
    double width;  // ������ ��������������
    double height; // ������ ��������������

public:
    Rectangle(double w, double h); // �����������
    double CalcArea() const override; // ��������������� ������ CalcArea
    void Show() const override;       // ��������������� ������ Show
};

#endif // RECTANGLE_H