#include "Metix.h"
//vector���
std::vector<double>& operator+(const std::vector<double>& x1, const std::vector<double>& x2)
{
    std::vector<double> x;
    for (int i = 0; i < x1.size(); i++)
        x.push_back(x1[i] + x2[i]);
    return x;
}

//���ж�Ӧ���
double Multiplication(const int line, const int row, const Metix& x1, const Metix& x2)
{
    double sum=0.0;
    for (int i = 0; i < line; i++)
        for (int j = 0; j < row; j++)
            sum += x1[i][j] * x2[j][i];
    return sum;
}

//�������
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
        std::cout << "���������ʽ����" << "\n";
        return New_metix;
    }
}

//�������
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
        std::cout << "���������ʽ����" << "\n";
        return New_metix;
    }
    // TODO: �ڴ˴����� return ���
}

//�������
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
        std::cout << "���������ʽ����" << "\n";
    return New_metix;
    // TODO: �ڴ˴����� return ���
}
