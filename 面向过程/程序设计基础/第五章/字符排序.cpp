#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
    string a, b, c, d;
    char fac(string a, string b, string c, string d);
    cout << "please enter number:";
    cin >> a >> b >> c >> d;
    fac(a, b, c, d);
    return 0;
}
char fac(string a, string b, string c, string d)
{
    string temp;
    if(a>b)
        {
            temp = b;
            b = a;
            a = temp;
        }
    
} 