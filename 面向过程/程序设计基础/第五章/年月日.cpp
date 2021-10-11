#include <iostream>
using namespace std;
int main()
{
    int x, y, z,sum=0;
    cout << "输入日期；";
    cin >> x >> y >> z;
    int a[13] = {0,31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(x%4==0&&x%100!=0||x%400==0)
        a[2] = 29;
        else
            a[2] = 28;
    for (int i = 1; i< y ;i++)
        sum += a[i];
    sum += z;
    cout << x << "." << y << "." << z << " "
         << "is this year's"
         << " ";
    cout << sum << " "
         << "days";
    return 0;
}