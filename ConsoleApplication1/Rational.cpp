#include "Rational.h"
#include <stdexcept>
#include <numeric>

void Rational::normalize() {
    if (denominator == 0) {
        throw std::runtime_error("Denominator cannot be zero");
    }

    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Rational::Rational() : numerator(0), denominator(1) {}
Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    normalize();
}

Rational Rational::operator+(const Rational& other) const {
    return Rational(numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Rational(numerator * other.denominator, denominator * other.numerator);
}

Rational operator+(const Rational& r, int value) {
    return r + Rational(value);
}

Rational operator+(int value, const Rational& r) {
    return Rational(value) + r;
}

Rational operator*(const Rational& r, int value) {
    return r * Rational(value);
}

Rational operator*(int value, const Rational& r) {
    return Rational(value) * r;
}

Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

bool Rational::operator==(const Rational& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numerator;
    if (r.denominator != 1) {
        os << "/" << r.denominator;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    int num, denom = 1;
    char slash;

    is >> num;

    if (is.peek() == '/') {
        is >> slash >> denom;
    }

    r = Rational(num, denom);
    return is;
}