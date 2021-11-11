#include <iostream>
using namespace std;
int main()
{
    int a[10];
    int i = 10;
    int *f = a;
    void sort(int *f, int i);
    void output(int *f, int i);
    for (int x = 0; x < i; x++)
        cin >> *(f + x);
    sort(f, i);
    output(f, i);
    return 0;
}

void fac(int *f, int i)
{
    for (int x = 0; x < i; x++)
        cin >> *(f + x);
}

void sort(int *f, int i)
{
    void exchange(int *x, int *y);
    int *min, *max, a = 0, b = 0;
    *min = *f;
    *max = *f;
    for (int j = 0; j < i - 1; j++)
    {
        if (*min > *(f + j + 1))
            a = j + 1;
        if (*max < *(f + j + 1))
            b = j + 1;
    }
    exchange(f + a, f);
    exchange(f + b, f + i - 1);
}

void output(int *f, int i)
{
    for (int x = 0; x < i; x++)
        cout << *(f + x) << " ";
}

void exchange(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}