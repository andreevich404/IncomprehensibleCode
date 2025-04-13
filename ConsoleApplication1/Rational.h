#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>
#include <stdexcept>

class Rational {
private:
    int numerator;
    int denominator;

    void normalize();

public:
    Rational();
    Rational(int num, int denom = 1);

    int Numerator() const { return numerator; }
    int Denominator() const { return denominator; }

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    friend Rational operator+(const Rational& r, int value);
    friend Rational operator+(int value, const Rational& r);
    friend Rational operator*(const Rational& r, int value);
    friend Rational operator*(int value, const Rational& r);

    Rational operator+() const;
    Rational operator-() const;

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};

#endif // RATIONAL_H