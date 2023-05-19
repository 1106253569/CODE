#include <iostream>
using namespace std;
int main()
{
    void input(int &a);
    void sort(int **p, int i);
    int n;
    int a[100];
    int *g[100], **p;
    cout << "please enter number";
    cin >> n;
    for (int i = 0; i < n; i++)
        g[i] = &a[i];
    for (int i = 0; i < n; i++)
        cin >> *g[i];
    p = g;
    sort(p, n);
    for (int i = 0; i < n; i++)
        cout << *g[i] << " ";
}

void sort(int **p, int n)
{
    void fac(int *x, int *y);
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (**(p + i) < **(p + j))
                fac(*(p + i), *(p + j));
}

void fac(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}