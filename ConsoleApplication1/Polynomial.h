#pragma once
#include "stdafx.h"

template <typename T>
class Polynomial {
private:
    std::vector<T> coefficients;

public:
    Polynomial();
    Polynomial(const T& scalar);
    Polynomial(const std::vector<T>& coeffs);

    size_t degree() const;
    T operator[](size_t power) const;
    T operator()(const T& x) const;

    bool operator==(const Polynomial<T>& other) const;
    bool operator!=(const Polynomial<T>& other) const;

    Polynomial<T> operator+(const Polynomial<T>& other) const;
    Polynomial<T> operator-(const Polynomial<T>& other) const;
    Polynomial<T> operator*(const Polynomial<T>& other) const;

    Polynomial<T>& operator+=(const Polynomial<T>& other);
    Polynomial<T>& operator*=(const Polynomial<T>& other);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Polynomial<U>& poly);
};

void demoPolynomial();