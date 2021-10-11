#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
    char a[20], b[10];
    char fac(char a[], char b[]);
    cout << "please enter a,b:";
    cin >> a >> b;
    string A, B;
    A = a[6];
    B = b[6];
    char a = fac(a, b);
    cout << "new word of a[] is" << a;
    cout<< strcat(a, b);
    cout << A + B;
    return 0;
}

char fac(char a[], char b[])
{
    int i, j;
    for (i = 0; a[i] != '\n';i++)
        a[i] = a[i];
    for (j = i; a[j] = '\n';j++)
        a[j] = b[j - i + 1];
    return (a);
}