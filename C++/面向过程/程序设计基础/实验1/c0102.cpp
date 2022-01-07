#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, i;
    cout << "please enter number:";
    cin >> n;
    if(99<n<1000)
    {
        int a[4];
        a[3] = n / 100;
        a[2] = n / 10 - a[3] * 10;
        a[1] = n - a[3] * 100 - a[2] * 10;
        n = a[1] * 100 + a[2] * 10 + a[3];
    }
    else
        n = -1;
    cout << n << endl;
    return 0;
}