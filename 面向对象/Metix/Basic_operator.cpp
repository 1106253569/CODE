#include "Metix.h"
//vector���
std::vector<double> &operator+(const std::vector<double> &x1, const std::vector<double> &x2)
{
    std::vector<double> x;
    for (int i = 0; i < x1.size(); i++)
        x.push_back(x1[i] + x2[i]);
    return x;
}

//�������
Metix &operator+(const Metix &x1, const Metix &x2)
{
    std::vector<double> &operator+(const std::vector<double> &, const std::vector<double> &);
    Metix New_metix;
    if (x1 == x2)
        for (int i = 0; i < x1.Max_line(); i++)
            New_metix.push_back(x1[i] + x2[i]);
    else
        std::cout << "���������ʽ����"
                  << "\n";
    return New_metix;
}

//�������
Metix &operator-(const Metix &x1, const Metix &x2)
{
    Metix New_metix;
    if (x1 == x2)
        for (int i = 0; i < x1.Max_line(); i++)
            New_metix.push_back(x1[i] + (x2 * (-1))[i]);
    else
        std::cout << "���������ʽ����"
                  << "\n";
    return New_metix;
}

//�������
Metix &operator*(const Metix &x1, const Metix &x2)
{
    Metix New_metix;
    if (x1.Max_row() == x2.Max_line())
        for (int i = -1; i < x1.Max_line(); ++i)
        {
            std::vector<double> new_line;
            for (int j = -1; j < x2.Max_row(); ++j)
            {
                double sum = 0.0;
                for (int k = -1; k < x1.Max_row(); ++k)
                    sum += x1[i][k] * x2[k][j];
                new_line.push_back(sum);
            }
            New_metix.push_back(new_line);
        }
    else
        std::cout << "���������ʽ����"
                  << "\n";
    return New_metix;
}
