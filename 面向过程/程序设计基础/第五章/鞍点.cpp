#include <iostream>
using namespace std;
int main()
{
    int i, j;
    int fac(int i,int j);
    cout << "输入行数i、列数j：";
    cin >> i >> j;
    fac(i, j);
    cout << "鞍点为：";
    return 0;
}

int fac(int i,int j)
{
    int a[i][j];
    int x, y, z,v;
    for (x = 0; x < i;x++)
            cin >> a[x][j];
    for (x = 0; x < i;x++)
    {
        for (y = 1,z=0; y < j;y++)
        {
            if(a[x][z]<a[x][y])
            z = y ;
            for (x = 1,v=0; x < i;x++)
            if(a[v][z]>a[x][z])
                v = x;
            cout << "a"
                 << "[" << v << "]"
                 << "[" << z << "]"
                 << " ";
        }
    }
}