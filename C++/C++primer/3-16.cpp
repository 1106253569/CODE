#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    void shuchu(vector<int> example);
    void shuchu(vector<string> example);
    vector <int> v1;
    shuchu(v1);
    vector<int> v2(10);
    shuchu(v2);
    vector<int> v3(10, 42);
    shuchu(v3);
    vector<int> v4{10};
    shuchu(v4);
    vector<int> v5{10, 42};
    shuchu(v5);
    vector<string> v6{10};
    shuchu(v6);
    vector<string> v7{10, "hi"};
    shuchu(v7);
    return 0;
}

void shuchu(vector<int> example)
{
    cout <<"数目为："<< example.size() << '\n';
    for(auto a:example)
        cout << a << '\n';
} 

void shuchu(vector<string> example)
{
    cout <<"数目为："<< example.size() << '\n';
    for(auto a:example)
        cout << a << '\n';
} 