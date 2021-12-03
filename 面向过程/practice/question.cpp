#include<iostream>
using namespace std;
int main()
{
    char ch[]="600";
    int s=0;
    for(int a=0;ch[a]>='0'&&ch[a]<='9';a++)
    {
        s=s*10;
        printf("%d\n",s);
        s=s+ch[a];
        printf("%d\n",s);
        s=s-'0';
        printf("%d\n",s);
    }
    return 0;
}