#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double f(double x);
    double fen(double n);
    double x;
    cout << "please enter number:";
    cin >> x;
    if (fen(x) != 0)
        cout << "区间"
             << "[" << x << "," << 2 * x << "]"
             << "零点为" << fen(x) << endl;
    return 0;
}

double f(double x)
{
    double y;
    y = x*cos(x) - 2; //函数
    return (y);
}

double fen(double n)
{
    double f(double x);
    double y1 ,y2, m1 = n, m2 = 2 * n;
    y1 = f(m1);
    y2 = f(m2);
    if(y1*y2>0)
    {
        cout << "区间"
             << "[" << n << "," << 2 * n << "]"
             << "无零点" << endl;
        return (0);
    }
    double det = m2 - m1;
    for (int i = 0; det > 1e-5;i++)
    {
        if(f(m1)*f((m1+m2)/2)<0)
        {
            m1 = m1;
            m2 = (m1+m2) / 2;
        }
        else
        {
            m1 = (m1+m2) / 2;
            m2 = m2;
        }
        det = m2 - m1;
    }
    return (m1);
}
