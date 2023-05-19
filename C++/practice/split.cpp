#include <iostream>
using namespace std;
void split(double x, int *iPart, double *fPart)
{
    *iPart = x;
    *fPart = x - *iPart;
}
int main()
{
    double n, x;
    int z;
    cout << "Please enter a real number:";
    cin >> n;
    cout << endl;
    split(n, &z, &x);
    cout << "This is a negative real number." << endl;
    cout << "Integer part = " << z << ", Decimal part = " << x;
    return 0;
}
