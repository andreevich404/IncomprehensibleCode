#ifndef SQUARE_SUMMATOR_H
#define SQUARE_SUMMATOR_H

#include "Summator.h"

class SquareSummator : public Summator {
public:
    // ��������������� transform ��� ��������� �����
    int transform(int i) const override {
        return i * i;
    }
};

#endif // SQUARE_SUMMATOR_H