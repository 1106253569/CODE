#include <iostream>
using namespace std;
int main()
{
    int a[15];
    int i,x,n=0;
    int fac(int i);
    cout << "输入数组：";
    for (i = 0; i < 15;i++)
        a[i] = fac(i);
    cout << "please enter number:";
    cin >> x;
    if(x==a[7])
        {
            cout << "该数为第" << 8 << "位元素";
            n += 1;
        }
    if (x < a[7])
        for (i = 0; i < 7; i++)
        {
            if (x == a[i])
            {
                cout << "该数为第" << i + 1 << "位元素";
                n += 1;
            }
        }
    if (x > a[7])
        for (i = 8; i < 15; i++)
        {
            if (x == a[i])
            {
                cout << "该数为第" << i + 1 << "位元素";
                n += 1;
            }
        }
    if(n==0)
        cout << "无此数";
    return 0;
}

int fac(int i)
{
    int y;
    cin >> y;
    return (y);
}