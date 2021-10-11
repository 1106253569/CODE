#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    double fac(double x);
    double s, y, x1, x2, sum, det, n;
    cout << "输入区间:";
    cin >> x1 >> x2;
    n = 1e9;
    det = (x2 - x1) / n;
    sum = 0;
    for (double i = x1; i <= x2; i += det)
        {
            y = fac(i);
            s = y * det;
            sum += s;
        }
        cout << "积分值为";
        cout << setiosflags(ios::fixed) << setprecision(5) << sum << endl;
    return 0;
}
double fac(double x)  //输入函数
{
    double y;
    y = x*x;
    return (y);
}
