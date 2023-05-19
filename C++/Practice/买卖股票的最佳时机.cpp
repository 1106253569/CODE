#include <iostream>
using namespace std;
int main()
{
    int prices[10000];
    int profit(int prices[]);
    int i=1;
    while(std::cin>>prices[i])
    i += 1;
    std::cout << profit(prices);
    return 0;
}

int profit(int prices[])
{
    int temp=0;
    for(int day=1;prices[day]!=0;day++)
    {
        for(int sale_day=day;prices[sale_day]!=0;sale_day++)
        {
            if(temp<prices[sale_day]-prices[day])
                temp = prices[sale_day] - prices[day];
        }
    }
    return (temp);
}