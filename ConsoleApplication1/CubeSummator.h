#ifndef CUBE_SUMMATOR_H
#define CUBE_SUMMATOR_H

#include "Summator.h"

class CubeSummator : public Summator {
public:
    // Переопределение transform для кубов чисел
    int transform(int i) const override {
        return i * i * i;
    }
};

#endif // CUBE_SUMMATOR_H