#include <iostream>
#include <string>
using namespace std;
int main()
{
    int fac(char *f);
    int conversion(char a);
    char a[100];
    char *f = a;
    int b[10];
    int *g = b;
    int j, x = 0;
    cout << "please enter number:";
    cin >> a;
    int n = fac(f);
    for (int i = 0; i < n;)
    {
        if (48 <= (int)*(f + i) && (int)*(f + i) <= 57)
        {
            *(g + x) = 0;
            for (j = i; 48 <= (int)*(f + j) && (int)*(f + i) <= 57; j++)
                *(g + x) = *(g + x) * 10 + conversion(*(f + j));
            i = j + 1;
            x++;
        }
        else
            i++;
    }
    for (int y = 0; *(g + y) != NULL; y++)
        cout << *(g + y) << endl;
    return 0;
}

int fac(char *f)
{
    int i, a;
    for (a = 0; *(f + a) != '\0'; a++)
    {
        int i = 1;
        i++;
    }
    return (a);
}

int conversion(char a)
{
    int x;
    x = (int)a - 48;
    return (x);
}