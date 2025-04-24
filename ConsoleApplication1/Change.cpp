#include "Change.h"

template <typename T>
bool change(T& elem1, T& elem2, T* array, size_t size) {
    bool hasElem1 = contains(elem1, array, size);
    bool hasElem2 = contains(elem2, array, size);

    if (!hasElem1 || !hasElem2) {
        std::cerr << "Ошибка: один или оба элемента не найдены в массиве\n";
        return false;
    }

    for (size_t i = 0; i < size; ++i) {
        if (array[i] == elem1) {
            array[i] = elem2;
        }
        else if (array[i] == elem2) {
            array[i] = elem1;
        }
    }

    std::cout << "Элементы успешно обменены\n";
    return true;
}

template bool change<int>(int&, int&, int*, size_t);
template bool change<double>(double&, double&, double*, size_t);
template bool change<std::string>(std::string&, std::string&, std::string*, size_t);

void demoChange() {
    using namespace std;

    cout << "\n=== Задание 2: Шаблонная функция change ===\n";

    // Тестирование с целыми числами
    int intArray[] = { 1, 2, 3, 4, 5 };
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    int a = 2, b = 4;

    cout << "Массив до обмена: ";
    for (size_t i = 0; i < intSize; ++i) cout << intArray[i] << " ";
    cout << endl;

    if (change(a, b, intArray, intSize)) {
        cout << "Массив после обмена: ";
        for (size_t i = 0; i < intSize; ++i) cout << intArray[i] << " ";
        cout << endl;
    }

    // Тестирование со строками
    string strArray[] = { "apple", "banana", "orange" };
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);
    string s1 = "banana", s2 = "orange";

    cout << "\nМассив до обмена: ";
    for (size_t i = 0; i < strSize; ++i) cout << strArray[i] << " ";
    cout << endl;

    if (change(s1, s2, strArray, strSize)) {
        cout << "Массив после обмена: ";
        for (size_t i = 0; i < strSize; ++i) cout << strArray[i] << " ";
        cout << endl;
    }

    // Тест с ошибкой (элемент не найден)
    double doubleArray[] = { 1.1, 2.2, 3.3 };
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    double d1 = 2.2, d2 = 4.4;
    cout << "\nПопытка обмена с несуществующим элементом:\n";
    change(d1, d2, doubleArray, doubleSize);
}