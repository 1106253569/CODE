#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int godbaha(int m);
    int fac(int m);
    int n,x;
    cout << "please enter n(>=6):";
    cin >> n;
    if(n%2==0)
        n = n;
        else
            n += 1;
        x = n - godbaha(n);
        cout << n << "=" <<x<<"+"<< godbaha(n-2) << endl;
        return 0;

}

int godbaha(int m)
{
    int prime(int o);
    int x,i,g;
    for (i = m; i >1;i--)
    { if(prime(i))
        break;
    };
    for (x = i; x > 2;x--)
    {
        if(x+i==m&&x!=1)
            x = 1;
    }
    if(x)
        g = i;
        else
        g = godbaha(i);
        return (g);
}

int prime(int o)
{ int i,b=1,y;
for(i=2;i<o/2&&b==1;i++)
{ if(o%i==0)
    b = 0;
}
if(b==0)
    return 0;
    else
        return 1;
}

