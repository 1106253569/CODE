#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double taile(double x);
    double x;
    cout << "please enter number:";
    cin >> x;
    cout << "Y=" << setiosflags(ios::fixed) << setprecision(5) << taile(x);
    return 0;
}

double taile(double x)
{
    int i;
    double y,sum;
    for (i = 0; i < 100;i++)
    {
        y = (pow((-1), i)*pow(x,i)) / i;
        sum += y;
    }
    return (sum);
}