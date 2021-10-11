#include <iostream>
using namespace std;
void main()
{
    int prices[100];
    int profit(int prices[]);
    int i=1;
    while(std::cin>>prices[i])
    i += 1;
    std::cout << profit(prices);
}

int profit(int prices[])
{
    int temp=0,sum_profit=0;
    for(int buy_day=1;prices[buy_day]!=0;buy_day++)
    {
        int do_day = buy_day;
        for(int sale_day=buy_day;prices[sale_day]!=0;sale_day++)
        {
            if(prices[sale_day]>prices[do_day])
                {
                    temp += prices[sale_day] - prices[do_day];
                    do_day = sale_day;
                }
                else
                    do_day = sale_day;
        }
        if(sum_profit<temp)
            sum_profit = temp;
        temp = 0;
    }
    return (sum_profit);
}