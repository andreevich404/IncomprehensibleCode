#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <iostream>

class Table {
private:
    int** data;  // Динамический двумерный массив для хранения таблицы
    int rows;    // Количество строк
    int cols;    // Количество столбцов

public:
    Table(int rows, int cols);
    ~Table();
    int get_value(int row, int col) const; // Метод для получения значения из ячейки
    void set_value(int row, int col, int value); // Метод для установки значения в ячейку
    int n_rows() const;        // Метод для получения количества строк
    int n_cols() const;        // Метод для получения количества столбцов
    void print() const;        // Метод для вывода таблицы на экран
    double average() const;    // Метод для вычисления среднего арифметического
};

#endif // TABLE_H