#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{ int g (int a ,int b, int c );
    int v, d, f, i;
    double x1, x2;
    cout << "plaese enter number:";
    cin >> v >> d >> f;
    i = g(v, d, f);
    if (i < 0)
        cout << "无根" << endl;
        else
        {
        x1 = ((-d) + sqrt(i)) / (2 * v);
        x2 = ((-d) - sqrt(i)) / (2 * v);
        cout << "方程组根为";
        cout << "x1=" << x1 << ",";
        cout << "x2=" << x2 << endl;
        };
return 0;
}

int g (int a ,int b, int c )
{ int m;
int q;
m = b * b - 4 * a * c;
return (m);
}

