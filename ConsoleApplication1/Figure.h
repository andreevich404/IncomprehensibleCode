#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
public:
    virtual double CalcArea() const = 0; // ����������� ����� ��� ���������� �������
    virtual void Show() const = 0;      // ����������� ����� ��� ������ ���������� � ������
    virtual ~Figure() {}                // ����������� ����������
};

#endif // FIGURE_H