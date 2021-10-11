#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
int f (int a ,int b);
int g (int a ,int b);
int c, d, m, n;
std::cout << "plaese enter number:";
std::cin >> c >> d;
m = f(c, d);
n = g(c, d);
cout << "最大公约数=" << m << endl;
cout << "最小公倍数=" << n << endl;
return 0;
}
int f (int a ,int b)
{
    int x;
    if (a > b)
        x = b;
    else
        x = a;
    for (x; x >= 1; x--)
    {
        if (a % x == 0 && b % x == 0)
            break;
    }
    return (x);
}
int g (int a ,int b)
{
    int y;
    if (a > b)
        y = a;
    else
        y = b;
    for (y; y <= a * b; y++)
    {
        if (y % a == 0 && y % b == 0)
            break;
    }
    return (y);
}

