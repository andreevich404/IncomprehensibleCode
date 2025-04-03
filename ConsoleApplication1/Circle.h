#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure {
private:
    double radius; // ������ �����

public:
    Circle(double r); // �����������
    double CalcArea() const override; // ��������������� ������ CalcArea
    void Show() const override;       // ��������������� ������ Show
};

#endif // CIRCLE_H