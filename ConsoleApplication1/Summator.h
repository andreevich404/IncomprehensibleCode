#ifndef SUMMATOR_H
#define SUMMATOR_H

class Summator {
public:
    virtual ~Summator() {} // Виртуальный деструктор

    // Виртуальный метод для преобразования числа
    virtual int transform(int i) const {
        return i; // По умолчанию: число без изменений
    }

    // Метод для вычисления суммы последовательности
    double sum(int N) const {
        double result = 0;
        for (int i = 1; i <= N; ++i) {
            result += transform(i);
        }
        return result;
    }
};

#endif // SUMMATOR_H