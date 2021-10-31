#include "Metix.h"
//vector相加
std::vector<double>& operator+(const std::vector<double>& x1, const std::vector<double>& x2)
{
    std::vector<double> x;
    for (int i = 0; i < x1.size(); i++)
        x.push_back(x1[i] + x2[i]);
    return x;
}

//行列对应相乘
double Multiplication(const int line, const int row, const Metix& x1, const Metix& x2)
{
    double sum=0.0;
    for (int i = 0; i < line; i++)
        for (int j = 0; j < row; j++)
            sum += x1[i][j] * x2[j][i];
    return sum;
}

//矩阵相加
Metix& operator+(const Metix& x1, const Metix& x2)
{
    std::vector<double>& operator+(const std::vector<double>&, const std::vector<double>&);
    x1.check();
    x2.check();
    Metix New_metix;
    if (x1 == x2)
    {
        for (int i = 0; i < x1.Max_line(); i++)
            New_metix.push_back(x1[i] + x2[i]);
        return New_metix;
    }
    else
    {
        std::cout << "输入变量格式错误" << "\n";
        return New_metix;
    }
}

//矩阵相减
Metix& operator-(const Metix& x1, const Metix& x2)
{
    x1.check();
    x2.check();
    Metix New_metix;
    if (x1 == x2)
    {
        for (int i = 0; i < x1.Max_line(); i++)
            New_metix.push_back(x1[i] + (x2 * (-1))[i]);
        return New_metix;
    }
    else
    {
        std::cout << "输入变量格式错误" << "\n";
        return New_metix;
    }
    // TODO: 在此处插入 return 语句
}

//矩阵相乘
Metix& operator*(const Metix& x1, const Metix& x2)
{
    x1.check();
    x2.check();
    Metix New_metix;
    if (x1 == x2)
        for (int i = 0; i < x1.Max_line(); i++)
        {
            std::vector<double> line;
            for (int j = 0; j < x1.Max_row(); j++)
            {
                line.push_back(Multiplication(i, j, x1, x2));
            }
            New_metix.push_back(line);
        }
    else
        std::cout << "输入变量格式错误" << "\n";
    return New_metix;
    // TODO: 在此处插入 return 语句
}
