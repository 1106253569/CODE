#include <iostream>
using namespace std;
int main()
{
    char a[3];
    int b[3];
    cout << "please enter word:";
    cin >> a[1];
    a[0] = a[1] - 1;
    a[2] = a[1] + 1;
    for (int i = 0; i < 3;i++)
        b[i] = (int)a[i];
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    cout << b[0] << " " << b[1] << " " << b[2] << endl;
    return 0;
}