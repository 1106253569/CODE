#include "Matrix.h"

//
void Matrix::check() const
{
    if (this->Max_line() != this->Max_row())
        throw std::out_of_range("line!=row");
}

//
Matrix &Matrix::operator*(int n) const
{
    for (int i = 0; i < this->Max_line(); i++)
        for (auto &j : (*this)[i])
            j *n;
}

Matrix::Matrix(std::istream &is)
{
    printf("�����������");
    int n;
    is >> n;
    printf("��������");
    int m;
    is >> m;
    printf("������ֵ");
    int i = 0, x = 0;
    while (i < n)
    {
        std::vector<double> line;
        while (line.size() <= m)
        {
            is >> x;
            line.push_back(x);
        }
        this->push_back(line);
        ++i;
    }
}

//
bool Matrix::operator==(const Matrix &M) const
{
    if (this->Max_line() == M.Max_line() && this->Max_row() == M.Max_row())
        return true;
    else
        return false;
}

//
int sort(const std::vector<int> &A)
{
    int k = 0, b = 1;
    for (int i = 1; i < A.size(); i++)
        for (int j = 0; j < i; j++)
            if (A[i] < A[j])
                ++k;
    return (b * pow(-1, k));
}

double Data(const Matrix &M, std::vector<double> &A, std::vector<int> &sub)
{
    int i = 0;
    double sum = 0.0;
    while (i < M.Max_line())
    {
        //Lambda
        if ([](int i, std::vector<int> &s) -> bool
            {
                for (const auto j : s)
                    if (i == j)
                        return false;
                return true;
            })
        {
            A.push_back(M[sub.size()][i]);
            sub.push_back(i);
            //
            if (A.size() == M.Max_row())
            {
                for (auto i : A)
                    sum += i;
                return sort(sub) * sum;
            }
            //
            else
                Data(M, A, sub);
        }
        else
            ++i;
    }
}
//
double Matrix::Dterminant() const
{
    check();
    //
    std::vector<double> data;
    //
    std::vector<int> subscript;
    return Data(*this, data, subscript);
}