#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() 
{
    int a, b, c;
    double s, S;
    cout << "please enter a,b,c:";
    cin >> a >> b >> c;
    s = (a + b + c) / 2;
    S = sqrt(s *(s - a) * (s - b) * (s - c));
    cout << "面积为";
    cout<<setiosflags(ios::fixed) << setprecision(3) << S << endl;
    return 0;
}