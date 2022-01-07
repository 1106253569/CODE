#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "please enter words:";
    getline(cin,s);
    string example = s;
    for(char &a:s)
    {
        a = 'x';
    }
    cout << s << endl;
    int i = 0;
    while(example[i]!=' ')
    {

        example[i] = 'X';
        ++i;
    }
    cout << example;
    return 0;
}