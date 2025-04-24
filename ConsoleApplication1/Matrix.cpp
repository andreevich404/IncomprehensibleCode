#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    if (rows == 0 || cols == 0) {
        throw invalid_argument("������� ������� �� ����� ���� ��������");
    }
    data.resize(rows, vector<T>(cols));
}

template <typename T>
Matrix<T>::Matrix(const vector<vector<T>>& input) {
    if (input.empty() || input[0].empty()) {
        throw invalid_argument("������� ������� �� ����� ���� ��������");
    }
    rows = input.size();
    cols = input[0].size();
    data = input;
}

template <typename T>
size_t Matrix<T>::getRows() const { return rows; }

template <typename T>
size_t Matrix<T>::getCols() const { return cols; }

template <typename T>
T Matrix<T>::get(size_t i, size_t j) const {
    if (i >= rows || j >= cols) {
        throw out_of_range("������� ������� �� ������� �������");
    }
    return data[i][j];
}

template <typename T>
void Matrix<T>::set(size_t i, size_t j, const T& value) {
    if (i >= rows || j >= cols) {
        throw out_of_range("������� ������� �� ������� �������");
    }
    data[i][j] = value;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("������� ������ ������ ��������� ��� ��������");
    }
    Matrix<T> result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template <>
Matrix<string> Matrix<string>::operator*(const Matrix<string>& other) const {
    if (cols != other.rows) {
        throw invalid_argument("���������� �������� ������ ������� ������ ��������� � ����������� ����� ������");
    }
    Matrix<string> result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] + " " + other.data[k][j]; // ������������ ����� � ��������
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        throw invalid_argument("���������� �������� ������ ������� ������ ��������� � ����������� ����� ������");
    }
    Matrix<T> result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
ostream& operator<<(ostream& os, const Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j] << "\t";
        }
        os << "\n";
    }
    return os;
}

template <typename T>
istream& operator>>(istream& is, Matrix<T>& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

void demoMatrix() {
    cout << "\n=== ������� 3: ��������� ����� Matrix ===\n";

    try {
        // ������������ � ������ �������
        vector<vector<int>> intData1 = { {1, 2}, {3, 4} };
        vector<vector<int>> intData2 = { {5, 6}, {7, 8} };

        Matrix<int> m1(intData1);
        Matrix<int> m2(intData2);

        cout << "������� m1:\n" << m1;
        cout << "������� m2:\n" << m2;
        cout << "m1 + m2:\n" << (m1 + m2);
        cout << "m1 * m2:\n" << (m1 * m2);

        // ������������ � double
        vector<vector<double>> doubleData1 = { {1.1, 2.2}, {3.3, 4.4} };
        Matrix<double> m3(doubleData1);
        cout << "\n������� m3 (double):\n" << m3;

        // ������������ �� ��������
        vector<vector<string>> strData1 = { {"a", "b"}, {"c", "d"} };
        vector<vector<string>> strData2 = { {"e", "f"}, {"g", "h"} };

        Matrix<string> m4(strData1);
        Matrix<string> m5(strData2);
        cout << "\n������� m4 (string):\n" << m4;
        cout << "������� m5 (string):\n" << m5;
        cout << "m4 + m5 (������������):\n" << (m4 + m5);
        cout << "m4 * m5 (����������� �������� ��� �����):\n" << (m4 * m5);
    }
    catch (const exception& e) {
        cerr << "������: " << e.what() << endl;
    }
}

template class Matrix<int>;
template class Matrix<double>;
template class Matrix<string>;

template ostream& operator<< <int>(ostream&, const Matrix<int>&);
template ostream& operator<< <double>(ostream&, const Matrix<double>&);
template ostream& operator<< <string>(ostream&, const Matrix<string>&);

template istream& operator>> <int>(istream&, Matrix<int>&);
template istream& operator>> <double>(istream&, Matrix<double>&);
template istream& operator>> <string>(istream&, Matrix<string>&);