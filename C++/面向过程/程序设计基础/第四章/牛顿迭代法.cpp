#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double fac(double x);
    double f(double x);
    double x;
    for (double i = 0; i <= 2;i+=1e-5)
    {
        int n = fac(i);
        if(n=1)
        {
            cout << i << endl;
        }
    }
    return 0;
}

double fac(double x)
{
    double der(double x);
    double f(double x);
    double x1;
    for (int i = 1; x > 1e-5;i++)
        {
            x = x - f(x) / der(x);
            if(i>1e5)
            {
                x = 0;
                break;
            }   
        }
        if(x!=0)
            x = 1;
        return (x);
}

double der(double x)
{
    double det = 1e-5, k; //det表示无穷小，k表示导数值
    double f(double x);   //输入函数f
    k = (f(x + det) - f(x)) / det;
    return (k);
}
double f(double x)
{
    double y;
    y = x*sin(x) - 1; //函数
    return (y);
}