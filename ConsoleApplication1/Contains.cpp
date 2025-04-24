#include "Contains.h"

template <typename T>
bool contains(const T& element, const T* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

template bool contains<int>(const int&, const int*, size_t);
template bool contains<double>(const double&, const double*, size_t);
template bool contains<std::string>(const std::string&, const std::string*, size_t);

void demoContains() {
    using namespace std;

    cout << "\n=== ������� 1: ��������� ������� contains ===\n";

    // ������������ � ������ �������
    int intArray[] = { 1, 2, 3, 4, 5 };
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    cout << "������ int: ";
    for (size_t i = 0; i < intSize; ++i) cout << intArray[i] << " ";

    cout << "\n�������� contains(3): " << boolalpha << contains(3, intArray, intSize);
    cout << "\n�������� contains(6): " << boolalpha << contains(6, intArray, intSize) << endl;

    // ������������ � double
    double doubleArray[] = { 1.1, 2.2, 3.3 };
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    cout << "\n������ double: ";
    for (size_t i = 0; i < doubleSize; ++i) cout << doubleArray[i] << " ";

    cout << "\n�������� contains(2.2): " << boolalpha << contains(2.2, doubleArray, doubleSize);
    cout << "\n�������� contains(4.4): " << boolalpha << contains(4.4, doubleArray, doubleSize) << endl;

    // ������������ �� ��������
    string strArray[] = { "apple", "banana", "orange" };
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);
    cout << "\n������ string: ";
    for (size_t i = 0; i < strSize; ++i) cout << strArray[i] << " ";

    cout << "\n�������� contains(\"banana\"): " << boolalpha
        << contains(string("banana"), strArray, strSize);
    cout << "\n�������� contains(\"grape\"): " << boolalpha
        << contains(string("grape"), strArray, strSize) << endl;
}