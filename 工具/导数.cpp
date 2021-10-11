#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double derivative(double x);
}

double derivative(double x)       //输入变量
{            
    double der(double x);
    cout<<setiosflags(ios::fixed) << setprecision(2) << der(x) << endl;
    return (x);
}
double der(double x)
{
    double det=1e-10, k;       //det表示无穷小，k表示导数值
    double f(double x);        //输入函数f
    k = (f(x + det) - f(x)) / det;
    return (k);
}
double f(double x)
{
    double y;
    y = x *x*x;          //函数
    return (y);
}