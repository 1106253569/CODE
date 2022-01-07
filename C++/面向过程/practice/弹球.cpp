#include <iostream>
using namespace std;
int main()
{
    int n;
    double y = 5, sum = 10;
    cout << "输入落地次数：";
    cin >> n;
    for (int i = 1; i < n;i++)
    {
        sum = sum + 2*y;
        y = y / 2;
    }
    cout << sum;
    return 0;
}