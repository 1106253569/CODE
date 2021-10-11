#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int naturn(int n)
{ int i,b=1;
for(i=2;i<n/2&&b==1;i++)
{ if(n%i==0)
            b = 0;
}
return (b); 
}
int main()
{ int naturn(int n);
int a,d;
cout<<"please enter a：";
cin>>a;
 d = naturn(a);
if(d==0) cout<<a<<"非素数"<<endl;
else cout<<a<<"素数"<<endl;
 return 0;
}

