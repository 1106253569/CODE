#include <iostream>
using namespace std;
struct day
{
    int year;
    int mouth;
    int day;
    int sum;
}day1;
int main()
{
    int days(int x, int y, int z);
    cout << "输入日期；";
    cin >> day1.year >> day1.mouth >> day1.day;
    day1.sum = days(day1.year, day1.mouth, day1.day);
    cout << day1.year << "." << day1.mouth << "." << day1.day << " "
         << "is this year's"
         << " ";
    cout << day1.sum << " "
         << "days";
    return 0;
}

int days(int x,int y,int z)
{
    int a[13] = {0,31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum=0;
    if(x%4==0&&x%100!=0||x%400==0)
        a[2] = 29;
        else
            a[2] = 28;
        for (int i = 1; i< y ;i++)
            sum += a[i];
        sum += z;
        return (sum);
}
