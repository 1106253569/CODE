#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int fac(int i);
    int n, sum;
    cout<< "pleace enter n:";
    cin >>n;
    sum = fac(n);
    cout << "平方和=" << sum << endl;
    return 0;
}

int fac(int i)
{
    int m,sum=0;
    m = i * i;
    i -= 1;
    if(i==0)
        sum += m;
        else
            sum =m+ fac(i);
        return (sum);
}