#include "Matrix.h"

//判断行列是否相等
void Matrix::check() const
{
    if (this->Max_line() != this->Max_row())
        throw std::out_of_range("line!=row");
}

//倍数矩阵
Matrix &Matrix::operator*(int n) const
{
    for (int i = 0; i < this->Max_line(); i++)
        for (auto &j : (*this)[i])
            j *n;
}

Matrix::Matrix(std::istream &is)
{
    printf("输入行数：");
    int n;
    is >> n;
    printf("输入列数：");
    int m;
    is >> m;
    printf("输入数字");
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

//判断同型矩阵
bool Matrix::operator==(const Matrix &M) const
{
    if (this->Max_line() == M.Max_line() && this->Max_row() == M.Max_row())
        return true;
    else
        return false;
}

//计算逆序数
int sort(std::vector<int> &A)
{
    int k = 0, b = 1;
    for (int i = 1; i < A.size(); i++)
        for (int j = 0; j < i; j++)
            if (A[i] < A[j])
                ++k;
    return (b * pow(-1, k));
}
//计算每行乘积和
double Data(const Matrix &M, std::vector<double> &A, std::vector<int> &sub)
{
    int i = 0;
    double sum = 0.0;
    while (i < M.Max_line())
    {
        //判断是否为新列
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
            if (A.size() == M.Max_row())
            {
                double temp;
                for (auto i : A)
                    temp = temp * i;
                sum += sort(sub) * temp;
            }
            //递归
            else
                Data(M, A, sub);
        }
        else
            ++i;
    }
    return sum;
}
//计算行列式
double Matrix::Dterminant() const
{
    check();
    //记录一次计算的值
    std::vector<double> data;
    //记录序列
    std::vector<int> subscript;
    return Data(*this, data, subscript);
}