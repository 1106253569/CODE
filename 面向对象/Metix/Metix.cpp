#include "Metix.h"

//判断行列是否相等
void Metix::check() const
{
    if (this->Max_line() != this->Max_row())
        throw std::out_of_range("line!=row");
}

//矩阵倍数相乘
Metix& Metix::operator*(int n) const
{
    for (int i = 0; i < this->Max_line(); i++)
        for (auto& j : (*this)[i])
            j* n;
}

Metix::Metix(std::istream&is)
{
    printf("输入矩阵阶数");
    int n;
    is >> n;
    printf("输入数值");
    int i = 0;
    int j = 0;
    int x = 0;
    while (i < n)
    {
        std::vector<double> line;
        while (j < n)
        {
            is >> x;
            line.push_back(x);
        }
        this->push_back(line);
    }
}

Metix::Metix(std::string&)
{
}

//判断同型矩阵
bool Metix::operator==(const Metix&M) const
{
    if (this->Max_line() == M.Max_line() && this->Max_row() == M.Max_row())
        return true;
    else
        return false;
}




 