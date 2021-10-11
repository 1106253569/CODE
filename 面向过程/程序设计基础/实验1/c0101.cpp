#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a[3];
    int sum;
    double mean;
    cout << "please enter number:";
    cin >> a[0] >> a[1] >> a[2];
    sum = a[0] + a[1] + a[2];
    mean = (double)sum / 3;
    cout << "sum=" << sum << endl;
    cout << "mean=" << setiosflags(ios::fixed) << setprecision(2) << mean << endl;
    return 0;
}