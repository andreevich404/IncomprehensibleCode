#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double re;
    double im;

public:
    Complex();
    Complex(double x, double y);
    Complex(const Complex& other);

    Complex& operator=(const Complex& other);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

    double getRe() const { return re; }
    double getIm() const { return im; }
    double modulus() const;
};

#endif