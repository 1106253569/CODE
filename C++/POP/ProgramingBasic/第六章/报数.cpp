#include <iostream>
using namespace std;
int main()
{
    int *check(int *f, int n);
    int n;
    cout << "please enter number:";
    cin >> n;
    int a[1000];
    for (int i = 1; i <= n; i++)
        a[i] = i;
    int *f = a;
    while (*(f + 3) != 0)
    {
        f = check(f, n);
    }
    cout << *(f + 1) << " " << *(f + 2);
    return 0;
}

int *check(int *f, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
            *(f + i) = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (*(f + i) == 0)
            for (int m = i; m <= n; m++)
                *(f + m) = *(f + m + 1);
    }
    return (f);
}