#include <iostream>
#include <cmath>
using namespace std;
int f(int x)
{ int sum;
sum=exp(x);
return (sum);
}
int main()
{ int f(int x);
int a,b,c;
cout<<"please enter a:";
cin>>a;
b=f(a);
c=1/f(a);
cout<<"sinh(x)="<<(b-c)/2;
return 0;
}
