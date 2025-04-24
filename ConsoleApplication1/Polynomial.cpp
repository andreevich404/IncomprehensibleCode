#include "Polynomial.h"

template <typename T>
Polynomial<T>::Polynomial() : coefficients(1) {}

template <typename T>
Polynomial<T>::Polynomial(const T& scalar) : coefficients(1, scalar) {}

template <typename T>
Polynomial<T>::Polynomial(const std::vector<T>& coeffs) : coefficients(coeffs) {}

template <typename T>
size_t Polynomial<T>::degree() const {
    for (size_t i = coefficients.size(); i > 0; --i) {
        if (coefficients[i - 1] != T(0)) {
            return i - 1;
        }
    }
    return 0;
}

template <typename T>
T Polynomial<T>::operator[](size_t power) const {
    return (power < coefficients.size()) ? coefficients[power] : T(0);
}

template <typename T>
T Polynomial<T>::operator()(const T& x) const {
    T result = T(0);
    T x_power = T(1);  // x^0

    for (size_t i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * x_power;
        x_power *= x;
    }

    return result;
}

template <typename T>
bool Polynomial<T>::operator==(const Polynomial<T>& other) const {
    size_t max_size = std::max(coefficients.size(), other.coefficients.size());
    for (size_t i = 0; i < max_size; ++i) {
        if ((*this)[i] != other[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Polynomial<T>::operator!=(const Polynomial<T>& other) const {
    return !(*this == other);
}

template <typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& other) const {
    size_t max_size = std::max(coefficients.size(), other.coefficients.size());
    std::vector<T> result_coeffs(max_size);

    for (size_t i = 0; i < max_size; ++i) {
        result_coeffs[i] = (*this)[i] + other[i];
    }

    return Polynomial<T>(result_coeffs);
}

template <typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& other) const {
    size_t result_size = coefficients.size() + other.coefficients.size() - 1;
    std::vector<T> result_coeffs(result_size, T(0));

    for (size_t i = 0; i < coefficients.size(); ++i) {
        for (size_t j = 0; j < other.coefficients.size(); ++j) {
            result_coeffs[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return Polynomial<T>(result_coeffs);
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial<T>& other) {
    *this = *this + other;
    return *this;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator*=(const Polynomial<T>& other) {
    *this = *this * other;
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Polynomial<T>& poly) {
    bool first = true;
    for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
        if (poly.coefficients[i] != T(0)) {
            if (!first) {
                os << " + ";
            }
            os << poly.coefficients[i];
            if (i > 0) {
                os << "x^" << i;
            }
            first = false;
        }
    }
    if (first) {
        os << "0";
    }
    return os;
}

template class Polynomial<int>;
template class Polynomial<double>;

template std::ostream& operator<< <int>(std::ostream&, const Polynomial<int>&);
template std::ostream& operator<< <double>(std::ostream&, const Polynomial<double>&);

void demoPolynomial() {
    using namespace std;

    cout << "\n=== Задание 4: Шаблонный класс Polynomial ===\n";

    // Тестирование с целыми числами
    Polynomial<int> p1({ 1, 2, 3 });  // 3x^2 + 2x + 1
    Polynomial<int> p2({ 0, 1, 0, 4 }); // 4x^3 + x

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << (p1 + p2) << endl;
    cout << "p1 * p2: " << (p1 * p2) << endl;
    cout << "p1(2): " << p1(2) << endl;

    // Тестирование с double
    Polynomial<double> p3({ 1.5, 0.0, 2.5 }); // 2.5x^2 + 1.5
    Polynomial<double> p4({ 0.0, 1.0 }); // x

    cout << "\np3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "p3 + p4: " << (p3 + p4) << endl;
    cout << "p3 * p4: " << (p3 * p4) << endl;
    cout << "p3(1.5): " << p3(1.5) << endl;
}