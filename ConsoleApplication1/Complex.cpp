#include "Complex.h"
#include <cmath>
#include <limits>
#include <stdexcept>

Complex::Complex() : re(0), im(0) {}
Complex::Complex(double x, double y) : re(x), im(y) {}
Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im,
        re * other.im + im * other.re);
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0) throw std::runtime_error("Division by zero");
    return Complex((re * other.re + im * other.im) / denom,
        (im * other.re - re * other.im) / denom);
}

Complex& Complex::operator++() {
    ++re; ++im;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++(*this);
    return temp;
}

Complex& Complex::operator--() {
    --re; --im;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    --(*this);
    return temp;
}

bool Complex::operator>(const Complex& other) const {
    return modulus() > other.modulus();
}

bool Complex::operator<(const Complex& other) const {
    return modulus() < other.modulus();
}

bool Complex::operator==(const Complex& other) const {
    return re == other.re && im == other.im;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re;
    if (c.im >= 0) os << " + " << c.im << "i";
    else os << " - " << -c.im << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    std::cout << "Real part: ";
    while (!(is >> c.re)) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter real part again: ";
    }

    std::cout << "Imaginary part: ";
    while (!(is >> c.im)) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter imaginary part again: ";
    }

    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return is;
}

double Complex::modulus() const {
    return sqrt(re * re + im * im);
}