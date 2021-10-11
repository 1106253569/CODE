#include <iostream>
using namespace std;
int main()
{
    char a[30];
    char *f = a;
    int i=0,m,x;
    int fac();
    cout << "please enter word:";
    cin >> a ;
    m = fac();
    for ( m; *(f+m-1)!='\0';m++,i++)
    {
        a[i] = *(f + m-1);
    }
    for (x = 0; x < i;x++)
        cout << a[x];
    return 0;
}

int fac(char *f)
{
    int i,a;
    for ( a = 0; *(f+a)!='\0';a++)
    {
        int i = 1;
        i++;
    }
    return (a);
}

int fac()
{
    int m;
    cout << "please enter number:";
    cin >> m;
    return (m);
}