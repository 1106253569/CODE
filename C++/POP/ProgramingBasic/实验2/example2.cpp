#include <iostream>
using namespace std;
int main()
{
    int fac(char *f);
    void password(char a[]);
    char a[100],word='z';
    cin >> a;
    for (int i = 0; i<50;i++)
    {
        for (int j = i+1; j<50;j++)
        {
            if(a[i]==a[j])
            {
                for (int k = j; k<50;k++)
                    a[k] = a[k + 1];
            }
        }
    }
    int c = fac(a);
    for (int i = 0; i < c / 2;i++)
    {
        char temp;
        temp = a[i];
        a[i]=a[c-1-i];
        a[c-1-i] = temp;
    }
    for (int i = c; i < c + 26; i++)
    {
            a[i] = word;
            word--;
    }
    for (int i = 0; a[i]!=0;i++)
    {
        for (int j = i+1; a[j]!=0;j++)
        {
            if(a[i]==a[j])
            {
                for (int k = j; a[k] != 0; k++)
                    a[k] = a[k + 1];
            }
        }
    }
    password(a);
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

void password(char a[])
{
    char b[100];
    int fac(char *f);
    cin >> b;
    int c = fac(b);
    for (int i = 0; i<c;i++)
    {
        if(b[i]!=0)
        {
            int j = (int)b[i]-97;
            b[i] = a[j];
        }
        cout << b[i];
    }
}
