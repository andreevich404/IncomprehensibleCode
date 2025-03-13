#include "Stock.h"

Stock::Stock() : capacity(10), size(0), serialCounter(0) {
    boxes = new Box[capacity];
}

Stock::~Stock() {
    delete[] boxes;
}

// Метод для добавления коробки на склад
void Stock::Add(int w, int v) {
    if (size >= capacity) {
        std::cerr << "Ошибка: превышено максимальное количество коробок." << std::endl;
        return;
    }

    boxes[size].weight = w;
    boxes[size].volume = v;
    boxes[size].serial = serialCounter++;

    size++;
    std::cout << "Коробка добавлена. Серийный номер: " << boxes[size - 1].serial << std::endl;
}

// Метод для получения коробки по минимальной грузоподъемности
int Stock::GetByW(int min_w) {
    int selectedSerial = -1;  // Серийный номер выбранной коробки
    int minWeight = INT_MAX;  // Минимальная грузоподъемность

    for (int i = 0; i < size; ++i) {
        if (boxes[i].weight >= min_w && boxes[i].weight < minWeight) {
            minWeight = boxes[i].weight;
            selectedSerial = boxes[i].serial;
        }
    }

    if (selectedSerial != -1) {
        std::cout << "Выдана коробка с серийным номером: " << selectedSerial << std::endl;
    }
    else {
        std::cout << "Подходящей коробки не найдено." << std::endl;
    }

    return selectedSerial;
}

// Метод для получения коробки по минимальному объему
int Stock::GetByV(int min_v) {
    int selectedSerial = -1;  // Серийный номер выбранной коробки
    int minVolume = INT_MAX;  // Минимальный объем

    for (int i = 0; i < size; ++i) {
        if (boxes[i].volume >= min_v && boxes[i].volume < minVolume) {
            minVolume = boxes[i].volume;
            selectedSerial = boxes[i].serial;
        }
    }

    if (selectedSerial != -1) {
        std::cout << "Выдана коробка с серийным номером: " << selectedSerial << std::endl;
    }
    else {
        std::cout << "Подходящей коробки не найдено." << std::endl;
    }

    return selectedSerial;
}
