#include <iostream>
using namespace std;
int main()
{
    void fac(int *x, int *y);
    int a, b, c;
    int *f, *g, *h;
    f = &a;
    g = &b;
    h = &c;
    cout << "please enter nuber:";
    cin >> a >> b >> c;
    if(a>b)
        fac(f, g);
        if(a>c)
            fac(f, h);
            if(b>c)
                fac(g, h);
            cout << *f << " " << *g << " " << *h;
            return 0;
}

void fac(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}