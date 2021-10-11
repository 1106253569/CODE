#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double juedui(const double b);
    double a;
    cin >> a;
    cout << a << "的绝对值为" << juedui(a) << '\n';
    cout << a << "的绝对值为" << abs(a) << '\n'; //利用cmath头文件中的abs函数
    return 0;
}

double juedui(const double b)
{
    if(b<0)
        return (-1 * b);
        else
            return b;
}