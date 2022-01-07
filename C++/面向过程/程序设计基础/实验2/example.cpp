#include <iostream>
using namespace std;
int main()
{
    double a=100.48546;
    int b;
    b = (int)a;
    a = a - b;
    for (int i = 1; a - (int)a > 0.00;i++)
    {
        a = a * 10;
        cout << a << endl;
    }
}