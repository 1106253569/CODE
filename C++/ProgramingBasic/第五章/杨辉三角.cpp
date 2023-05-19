#include <iostream>
using namespace std;
int main()
{
    int i;
    int fac(int x);
    cout << "please enter i:";
    cin >> i;
    int a[i][i];
    if(i==1)
        {a[0][0]=1;
            cout << a[0][0] << endl;
        }
    if(i>=2)
        fac(i);
    return 0;
}

int fac(int x)
{
    int i,j,k;
    int a[x][x];
    for (j = 0; j <= x;j++)
        for (k = 0; k <= x;k++)
            a[j][k] = 0;
    a[0][0] = 1;
    cout << a[0][0] << endl;
    for (j = 1; j <= x;j++)
        {
            for (k =0; k <= j;k++)
            if(k==0)
            {
                a[0][j] = 1;
                cout << a[0][j] << " ";
            }
            else
            { 
                a[k][j] = a[k - 1][j - 1] + a[k][j - 1];
                cout << a[k][j] << " ";
            }
            cout << endl;
        }
}