#include <iostream>
#include <string.h>
int main()
{
    char a[80] = "hello";
    char b[80] = "world";
    printf("%s\n", strcat(a, b));
    printf("%s", strcpy(a, b));
    return 0;
}