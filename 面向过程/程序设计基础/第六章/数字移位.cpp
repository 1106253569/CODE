#include <iostream>
using namespace std;
int main()
{
    int a[10];
    int i=10;
    int *f = a;
    int number();
    void sort(int *f, int i,int j);
    cout << "please enter nunber:";
    for (i = 0; i < 10;i++)
        cin >> *(f + i);
    int j = number();
    sort(f, i, j);
    for (i = 0; i < 10;i++)
        cout << *(f + i) << " ";
    return 0;
}

int number()
{
    int i;
    cout << "转移个数:";
    cin >> i;
    return (i);
}

void sort(int *f, int i,int j)
{
    int a[j];
    for (int x = 0; x < j;x++)
            a[x]=*(f + x)  ;
        for (int x = 0; x < i;x++)
            if(x<i-j)
                *(f + x) = *(f + j + x);
            else
                *(f + x) = a[x-i+j];
}