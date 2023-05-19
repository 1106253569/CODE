#include <iostream>
class Complex
{
    friend Complex operator-(const Complex &lhs, const Complex &rhs);
    friend Complex operator+(const Complex &lhs, const Complex &rhs);
    friend Complex operator+(const Complex &lhs, int i);
    friend std::ostream &operator<<(std::ostream &os, const Complex &M);
    friend std::istream &operator>>(std::istream &is, Complex &M);

public:
    double real = 0.0;
    double imag = 0.0;
    Complex() = default;
    Complex(double first, double second) : real(first), imag(second) {}
    Complex &operator=(const Complex &M)
    {
        this->real = M.real;
        this->imag = M.imag;
        return *this;
    }
};
