#include <iostream>
#include <string>
using namespace std;
int main()
{
    char word[100];
    int fac(char * f);
    cout << "please enter word:";
    cin >> word;
    char *f = word;
    int x = fac(f);
    cout << "长度为：" << x;
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