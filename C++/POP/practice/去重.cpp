#include <iostream>
char *fac(char a[])
{
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
    return (a);
}