#include <iostream>
using namespace std;
int main()
{
    char a[5];
    cin >> a;
    if(a[0]==a[4]&&a[1]==a[3])
        cout << "this number is a hui wen";
        else
            cout << "this number is not a hui wen";
}