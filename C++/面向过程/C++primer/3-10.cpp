#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string example;
    getline(cin, example);
    for(auto &a:example)
    {
        if(!ispunct(a))
            cout << a;
    }
    cout << '\n';
    string news;
    for(auto &a:example)
    {
        if(!ispunct(a))
            news += a;
    }
    cout << news;

}