#pragma once
#include "stdafx.h"

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols);
    Matrix(const std::vector<std::vector<T>>& input);

    size_t getRows() const;
    size_t getCols() const;
    T get(size_t i, size_t j) const;
    void set(size_t i, size_t j, const T& value);

    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);

    template <typename U>
    friend std::istream& operator>>(std::istream& is, Matrix<U>& matrix);
};

void demoMatrix();
