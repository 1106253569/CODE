#include <stdio.h>
int main()
{
    char a[50],b[50];
    char *str_bin(char *s, char *t);
    scanf("%c,%c", a, b);
    char *g;
    g = str_bin(a, b);
    for (int i = 0; *(g + i) != '\0';i++)
        printf("%c", *(g + i));
}
char *str_bin( char *s, char *t )
{
    int fac(char *f);
    int n=fac(s);
    char *g;
    g = s;
    for (int j = 0; j <= fac(t);j++)
        *(g+j+n) = *(t + j);
    return (g);
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