#include <iostream>
using namespace std;
int main()
{
    int a[5][5];
    int *b[5];
    void input(int *x, int *y);
    cout << "请输入数列：" << endl;
    for (int i = 0; i < 5;i++)
        for (int j = 0; j < 5;j++)
            cin >> a[i][j];
    cout << "原矩阵为：" << endl;
    for (int i = 0; i < 5;i++)
        {
            for (int j = 0; j < 5;j++)
                cout << a[i][j] << " ";
                cout << endl;
        }
    for (int i = 0; i < 5;i++)
        for (int j = 0; j < 5;j++)
            if (*b[i]<a[i][j])
                *b[i] = a[i][j];    
    for (int i = 1; i < 5;i++) 
        if(*b[0]<*b[i])
             *b[0] = *b[i];
    a[2][2] = *b[0];
    cout << "矩阵为：" << endl;
    for (int i = 0; i < 5;i++)
        {
            for (int j = 0; j < 5;j++)
                cout << a[i][j] << " ";
                cout << endl;
        }
        return 0;
}