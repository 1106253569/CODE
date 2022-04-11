#include <iostream>
using namespace std;
int main()
{
    int s=0, n, i,sum;
    cout << "please enter number:";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        sum = 0;
        for (int x = 1; x <= i;x++)
        {
           sum += x;
        }
        s += sum;
    }
    cout << "和"
         << "=" << s;
    return 0;

}