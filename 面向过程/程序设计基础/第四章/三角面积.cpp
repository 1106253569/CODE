#include <iostream>
#include <cmath>
#define fac(a,b,c) (a + b + c) / 2;
#define area(a,b,c,s) sqrt(s *(s - a) * (s - b) * (s - c));
using namespace std;
int main() 
{
    double a, b, c, s, f;
    cout << "please enter a,b,c:";
    cin >> a >> b >> c;
    f = fac(a, b, c);
    s = area(a,b,c,f);
    cout << "面积为" << s << endl;
    return 0;
}