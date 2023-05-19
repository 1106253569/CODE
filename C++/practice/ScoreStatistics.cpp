#include <stdio.h>

int main()
{
    int a[101] = {0};
    int n = 0;
    int num;
    while (n < 100000 && scanf("%d", &num) != EOF)
    {
        if (num >= 0 && num <= 100)
            a[num] += 1;
        n++;
    }

    int max = 0;
    for (int j = 0; j < 101; j++)
        if (a[j] > max)
            max = a[j];

    for (int i = 0; i < 101; i++)
        if (a[i] == max)
            printf("%d\n", i);
    return 0;
}
