#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int sum;
int main()
{
    int input(int x);
    int sort(int a[], int n);
    int n;
    int a[10][10];
    cout << "输入行列式阶数：";
    cin >> n;
    if (n == 3) //计算三阶矩阵
    {
        for (int i = 1; i <= 3; i++)
            for (int j = 1; i <= 3; j++)
                input(a[i][j]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j != i)
                    for (int k = 1; k <= n; k++)
                    {
                        if (k != j && i)
                        {
                            int n;
                            int b[3];
                            b[0] = a[1][i], b[1] = a[2][j], b[2] = a[3][k];
                            n = sort(b, n);
                            sum += n * b[0] * b[1] * b[2];
                        }
                    }
            }
        }
    }
    cout << "行列式值为：" << sum;
    return 0;
}

int input(int x)
{
    cin >> x;
}

int sort(int a[], int n) //计算行列式排列
{
    int k = 0, b = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] < a[j])
                k++;
    for (int x = 0; x < k; x++)
        b *= (-1);
    return (b);
}