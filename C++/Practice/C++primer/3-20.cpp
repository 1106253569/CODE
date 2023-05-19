#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<int> number;
    int y;
    char word;
    while(cin>>y)
    {
        number.push_back(y);
        cout << "continue?  ";
        cin >> word;
        if(word!='y'&&word!='Y')
        {
            break;
        }
    }
    for (int x = 1; x < number.size();)
    {
        auto sum = number[x] + number[x - 1];
        cout << sum << '\n';
        ++x;
    }
    for (int a = 0; a < number.size() / 2;)
    {
        auto sum = number[a] + number[number.size() - 1 - a];
        cout << sum << '\n';
        ++a;
    }
    return 0;
}