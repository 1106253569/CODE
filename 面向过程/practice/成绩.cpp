#include <iostream>
#include <string>
using namespace std;
int main()
{
    int data;
    while(cin>>data)
    {
        cout << "等级为";
        if(data>=100)
        {
            cout << "A++" << endl;
            continue;
        }
        int temp=data/10-5;
        char grade = 69 - temp;
        if(temp<=0)
            cout << "F" << endl;
        else
            cout << grade << endl;
    }
    return 0;
}