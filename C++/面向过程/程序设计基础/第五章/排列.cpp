#include <iostream>
using namespace std;
int main()
{
    int a[11];
    int i,t,x;
    cout << "please enter number:" << endl;
    for (i = 1; i <= 10;i++)
        cin >> a[i];
    cout << endl;
    for (i = 1; i <= 9;i++)
        for (t = 1; t <= 10-i;t++)
        if(a[i]>a[i+1]) 
        {
            x = a[i];
            a[i] = a[i+1];
            a[i+1] = x;
        }

    cout << "the sorted numbers:" << endl;
    for (i = 1; i < 11;i++)
        cout << a[i] << " ";
    return 0;
}