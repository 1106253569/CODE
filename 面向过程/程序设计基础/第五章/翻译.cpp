#include <iostream>
using namespace std;
int main()
{
    char str[52];
    cout << "please enter password:";
    cin >> str;
    cout << "password:" << str << " "
         << "be translated to"<<" ";
    for (int i = 0; i<52;i++)
    {
        int x = str[i];
        if(x<=90)
            str[i] = '\(64 + (27 - (x - 64)))';
            else
                str[i] = '\(96 + (27 - (x - 96)))';
        cout << str[i];
    }
    return 0;
}