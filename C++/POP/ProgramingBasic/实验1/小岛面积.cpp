#include<iostream>
using namespace std;

int map[10][10],sum;

int xpd(int a,int b,int n) 
{
    for(int k=1;k<a;k++) 
    {
        if(map[k][b]==1) 
        {
            for(int k=a+1;k<=n;k++) 
            {
                if(map[k][b]==1) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int ypd(int a,int b,int n) 
{
    for(int k=1;k<b;k++) 
    {
        if(map[a][k]==1) 
        {
            for(int k=b+1;k<=n;k++) 
            {
                if(map[a][k]==1) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() 
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) 
    {
		for(int j=1;j<=n;j++) 
        {
			cin>>map[i][j];
		}
	}	
	for(int i=1;i<=n;i++) 
    {
		for(int j=1;j<=n;j++) 
        {
			if(map[i][j]==0&&xpd(i,j,n)&&ypd(i,j,n)) 
            {
				sum++;
			}
		}
	}
	cout<<sum;
	return 0; 
}
