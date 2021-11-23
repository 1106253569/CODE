#include <stdio.h>
int main()
{
    int a[10];
    int max = 0;
    for (int i = 0; i < 10;i++)
        scanf("%d", &a[i]);
    for (int j = 0; j < 10;j++)
    {
        if(a[j]>max)
            max = a[j];
    }
    printf("max=%d", max);
    return 0;
}