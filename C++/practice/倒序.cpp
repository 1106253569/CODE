#include <iostream>
void exchange(char a[],int n)
{
    int fac(char *f);
    int n = fac(a);
    for (int i = 0; i < n / 2;i++)
    {
        char temp;
        temp = a[i];
        a[i]=a[n-1-i];
        a[n-1-i] = temp;
    }
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