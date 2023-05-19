#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int i, j, n, a;
    int c[100][100];
    cin >> a >> n;
    c[0][0] = a;
    for (i = 1; i < n; i++)
    {
        c[i][i] = c[i - 1][i - 1] + i * 2;
        for (j = i; j >= 0; j--)
            c[j - 1][i] = c[j][i] - 1;
        for (j = i; j >= 0; j--)
            c[i][j - 1] = c[i][j] + 1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout << setw(4) << setiosflags(ios::right) << c[i][j];
        cout << endl;
    }
    return 0;
}