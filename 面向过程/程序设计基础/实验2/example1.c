#include <stdio.h>
int main() 
{
    int num[50], i, j, tmp, t = 0;
    float sum = 0;
    do
    {
        scanf("%d", &num[t]);
    }while (num[t++]!=-1);
    t = t - 1;
    for (i = 0; i < t-1; i++) 
    {
        for (j = i+1; j < t; j++) 
        {
            if (num[i] > num[j]) 
            {
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
    for (i = 2; i < t-2; i++) 
    {
        sum += num[i];
    }
    printf("%.2f", sum / (t - 4));
    getchar(); getchar();
}
