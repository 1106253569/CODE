#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> word;
    string s;
    char x;
    while(cin>>s)
    {
        word.push_back(s);
        cout << "Continue?  ";
        cin >> x;
        if(x!='Y'&&x!='y')
            break;
    }
    for(auto &a:word)
    {
        for(auto &b:a)
            b = toupper(b);
        cout << a<<'\n';
    }
    return 0;
}