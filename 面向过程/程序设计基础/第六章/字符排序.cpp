#include <iostream>
#include <string>
using namespace std;
int main()
{
    void fac(string * x, string * y);
    string a, b, c;
    string *f, *g, *h;
    f = &a;
    g = &b;
    h = &c;
    cout << "please enter word:";
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

void fac(string *x,string *y)
{
    string temp;
    temp = *x;
    *x = *y;
    *y = temp;
}