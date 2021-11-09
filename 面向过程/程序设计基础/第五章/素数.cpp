#include <iostream>
using namespace std;
int main()
{
    int b, i, j;
    int a[100];
    int naturn(int i);
    cout << "一百以内的素数有：";
    for (i = 0; i < 100; i++)
    {
        a[i] = i + 1;
        b = naturn(a[i]);
        if (b == 1)
            cout << a[i] << endl;
    }
    return 0;
}

int naturn(int n)
{
    int i, b = 1;
    for (i = 2; i < n / 2 && b == 1; i++)
    {
        if (n % i == 0)
            b = 0;
    }
    return (b);
}