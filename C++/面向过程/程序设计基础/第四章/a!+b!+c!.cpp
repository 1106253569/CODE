#include <iostream>
using namespace std;
int fac(int x)
{ int sum=1,i;
if(x==0) sum=1;
else for(i=1;i<=x;i++)
sum*=i;
return 	(sum);
}
int main()
{ int fac(int x);
int a,b,c;
cout<<"please enter number:";
cin>>a>>b>>c;
cout<<"a!+b!+c!="<<fac(a)+fac(b)+fac(c)<<endl;
return 0;
}
