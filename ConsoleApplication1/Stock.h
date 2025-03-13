#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <climits>

class Stock {
private:
    struct Box {
        int weight;  // Грузоподъемность коробки
        int volume;  // Объем коробки
        int serial;  // Серийный номер коробки
    };

    Box* boxes;       // Динамический массив коробок
    int capacity;     // Вместимость массива
    int size;         // Текущее количество коробок
    int serialCounter; // Счетчик для серийных номеров

public:
    Stock();
    ~Stock();

    void Add(int w, int v);  // Добавить коробку на склад
    int GetByW(int min_w);   // Получить коробку по минимальной грузоподъемности
    int GetByV(int min_v);   // Получить коробку по минимальному объему
};

#endif // STOCK_H