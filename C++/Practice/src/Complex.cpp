#include "Complex.h"

Complex operator-(const Complex &lhs, const Complex &rhs)
{
    Complex New_complex;
    New_complex.imag = lhs.imag - rhs.imag;
    New_complex.real = lhs.real - rhs.real;
    return New_complex;
}
Complex operator+(const Complex &lhs, const Complex &rhs)
{
    Complex New_complex;
    New_complex.imag = lhs.imag + rhs.imag;
    New_complex.real = lhs.real + rhs.real;
    return New_complex;
}
Complex operator+(const Complex &lhs, int i)
{
    Complex New_complex;
    New_complex.real = lhs.real + i;
    New_complex.imag = lhs.imag;
    return New_complex;
}
std::ostream &operator<<(std::ostream &os, const Complex &M)
{
    if (M.imag > 0)
        os << '(' << M.real << '+' << M.imag << 'i' << ')';
    else
        os << '(' << M.real << '+' << M.imag << 'i' << ')';
    os << '\n';
    return os;
}
std::istream &operator>>(std::istream &is, Complex &M)
{
    is >> M.real;
    is >> M.imag;
    return is;
}