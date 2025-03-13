#include "Complex.h"

Complex::Complex() {
    re = new double(0);
    im = new double(0);
}

Complex::Complex(double x, double y) {
    this->re = new double(x);
    this->im = new double(y);
}

Complex::~Complex() {
    delete re;
    delete im;
}

// Установка действительной части
void Complex::SetRe(double x) {
    *re = x;
}

// Установка мнимой части
void Complex::SetIm(double y) {
    *im = y;
}

// Получение действительной части
double Complex::GetRe() const {
    return *re;
}

// Получение мнимой части
double Complex::GetIm() const {
    return *im;
}

// Вычисление модуля комплексного числа
double Complex::Abs() const {
    return std::sqrt((*re) * (*re) + (*im) * (*im));    // Формула: sqrt(re^2 + im^2)
}

// Вычисление аргумента комплексного числа
double Complex::Arg() const {
    return std::atan2(*im, *re);    // Формула: atan2(im, re)
}

// Вывод числа в алгебраической форме
void Complex::Print() const {
    std::cout << *re << " + i*" << *im << std::endl;    // Формат: a + bi
}

// Вывод числа в тригонометрической форме
void Complex::TrigPrint() const {
    double rho = Abs();
    double phi = Arg();
    std::cout << rho << " * (cos(" << phi << ") + i*sin(" << phi << "))" << std::endl;  // Формат: r * (cos(phi) + i*sin(phi))
}

// Вывод числа в экспоненциальной форме
void Complex::ExpPrint() const {
    double rho = Abs();
    double phi = Arg();
    std::cout << rho << " * e^(i*" << phi << ")" << std::endl;  // Формат: r * e^(i*phi)
}

// Сложение двух комплексных чисел
Complex Complex::Add(const Complex& z) const {
    return Complex(*re + *z.re, *im + *z.im);   // Формула: (a + bi) + (c + di) = (a + c) + (b + d)i
}

// Вычитание комплексных чисел
Complex Complex::Sub(const Complex& z) const {
    return Complex(*re - *z.re, *im - *z.im);   // Формула: (a + bi) - (c + di) = (a - c) + (b - d)i
}

// Умножение комплексных чисел
Complex Complex::Mult(const Complex& z) const {
    return Complex(*re * *z.re - *im * *z.im, *re * *z.im + *im * *z.re);   // Формула: (a + bi) * (c + di) = (a*c - b*d) + (a*d + b*c)i
}

// Деление комплексных чисел
Complex Complex::Div(const Complex& z) const {
    double denominator = *z.re * *z.re + *z.im * *z.im; // Знаменатель: c^2 + d^2
    return Complex((*re * *z.re + *im * *z.im) / denominator, (*im * *z.re - *re * *z.im) / denominator);   // Формула: (a + bi) / (c + di) = [(a*c + b*d) + (b*c - a*d)i] / (c^2 + d^2)
}
