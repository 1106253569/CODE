#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> vlint;
    string i;
    while(cin>>i)
    {
        vlint.push_back(i);
        char s;
        cout << "continue?";
        cin >> s;
        if(s!='y')
            break;
    }
    for (auto x = vlint.begin(); x != vlint.end();++x)
    {
        cout << *x<<'\n';
    }
    cout << vlint.size();
    return 0;
}