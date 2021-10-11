#include <iostream>
using namespace std;
int main()
{
    int a[3][3];
    cout << "请输入数列：" << endl;
    for (int i = 0; i < 3;i++)
        for (int j = 0; j < 3;j++)
            cin >> a[i][j];
    cout << "原矩阵为：" << endl;
    for (int i = 0; i < 3;i++)
        {
            for (int j = 0; j < 3;j++)
                cout << a[i][j] << " ";
                cout << endl;
        }
    for (int i = 0; i < 3;i++)
        for (int j = i; j < 3;j++)
        {
            int temp = a[i][j];
            if(i!=j)
                {
                    a[i][j]=a[j][i];
                    a[j][i] = temp;
                }
        }
    cout << "转置矩阵为：" << endl;
    for (int i = 0; i < 3;i++)
        {
            for (int j = 0; j < 3;j++)
                cout << a[i][j] << " ";
                cout << endl;
        }
        return 0;
}

