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

int main()
{
    Complex c1, c2;
    std::cout << c1;
    std::cout << c1 + c2;
    std::cout << c1 + 2;
    return 0;
}
