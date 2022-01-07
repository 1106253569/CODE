#include <iostream>
using namespace std;
int main()
{
    int i, j, k;
    int fac(int array[3][3] );
    int a[3][3];
    cout << "please enter:" << endl;
    for (i = 0; i < 3;i++)
        for (j = 0; j < 3;j++)
            cin >> a[j][i];
    cout << "sum=" << fac(a) << endl;
    return 0;
}

int fac(int array[3][3])
{
    int sum;
    sum = array[1][1] * (array[0][0] * array[2][2] + array[0][2] * array[2][0]);
    return (sum);
}