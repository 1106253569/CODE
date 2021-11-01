#include <iostream>
class MyComplex
{
    friend MyComplex &operator-(const MyComplex &lhs,const MyComplex &rhs);

private:
    double real = 0.0;
    double imag = 0.0;

public:
    MyComplex() = default;
    MyComplex(double first,double second):real(first),imag(second){}
    MyComplex &operator-=(const MyComplex &M)
    {
        this->real -= M.real;
        this->imag -= M.imag;
        return *this;
    }
    MyComplex &operator+=(const MyComplex &M)
    {
        this->real += M.real;
        this->imag += M.imag;
        return *this;
    }
};

MyComplex &operator-(const MyComplex &lhs, const MyComplex &rhs)
{
    MyComplex New_complex;
    New_complex.imag = lhs.imag - rhs.imag;
    New_complex.real = lhs.imag - rhs.imag;
    return New_complex;
}