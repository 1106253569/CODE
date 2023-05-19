#include <iostream>
using namespace std;
int main()
{
    int fac();
    int n,max,min;
    int a[n];
    cout << "please enter number:";
    n = fac();
    for (int i = 0; i < n;i++)
        cin>>a[i];
    max = a[0];
    min = a[0];
    for (int i = 1; i < n; i++)
    {
        if(max<a[i])
            max = a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if(min>a[i])
            min = a[i];
    }
    cout << "最大值为" << max << endl;
    cout << "最小值为" << min << endl;
    return 0;
}

int fac()
{
    int n;
    cin >> n;
    return (n);
}