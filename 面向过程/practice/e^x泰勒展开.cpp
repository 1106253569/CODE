#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double taile(int x);
    int x;
    cout << "please enter number:";
    cin >> x;
    cout << "e^" << x << "=" << taile(x);
    return 0;
}

double taile(int x)
{
    int jiecheng(int x);
    int i=0;
    double taile=0.0;
    for (i = 0; i < 16;i++)
    {
        taile += pow(x, i) / jiecheng(i);
    }
    return (taile);
}
int jiecheng(int x)
{
    int sum = 1, i;
    if (x == 0)
        sum = 1;
    else
        for (i = 1; i <= x; i++)
            sum *= i;
    return (sum);
}
