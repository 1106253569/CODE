#include <iostream>
#include <string>
using namespace std;
int main()
{
    string m[12] =
        {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"};
    string *mouth = m;
    int a;
    cout << "please enter your want to search mouth:";
    cin >> a;
    cout << *(mouth + (a - 1));
}