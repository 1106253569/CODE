/*
实 验 二 类的定义及使用
任务描述：
1、设计一个计数器类（Counter)，其数据成员包括计数器的值；成员函数包括：
(1)初始化（要求使用带默认参数的构造函数实现，默认参数值设为6）；
(2)计数器加1；
(3)计数器减1；
(4)显示计数器的值。
2、设计一个时间类（Time) ，其数据成员包括时，分，秒；成员函数包括：
(1)加一秒；
(2)按24小时制显示时间universialhour()；
(3)按12小时制显示时间normalshow()。

要求分别使用有参数，无参数的构造函数实现数据成员的初始化。
一、实验目的和要求
1、 熟悉类的定义及数据成员和成员函数的设计，了解面向对象程序设计思路。
2 、了解成员函数的定义方式。
二、项目拟实现的主要源代码（设计每个类的成员以及内部函数，完成代码）
1、设计一个计数器类（Counter)
*/

#include <Windows.h>
#include <iostream>
using namespace std;
class Time
{
private:
    int hour;
    int second;
    int minute;

public:
    Time(int h, int m, int s)
    {
        hour = h;
        second = s;
        minute = m;
    }
    void add();
    void normalShow();
    void universialhour();
};

void Time::add()
{
    second += 1;
    if (second >= 60)
    {
        second = 0;
        minute += 1;
    }
    if (minute >= 60)
    {
        hour++;
        minute = 0;
    }
    if (hour >= 24)
    {
        hour -= 24;
    }
}

void Time::universialhour()
{
    std::cout << hour << ":" << minute << ":" << second << std::endl;
}

void Time::normalShow()
{
    if (hour >= 12)
    {
        int temp = hour - 12;
        cout << temp << ":" << minute << ":" << second << "PM"
             << "\n";
    }
    else
        cout << hour << ":" << minute << ":" << second << "AM"
             << "\n";
}
int main()
{
    Time t1(23, 59, 0);
    Time t2(23, 59, 0);
    for (int i = 0; i < 60; i++)
    {
        t1.add();
        t2.add();
        t1.normalShow();
        t2.universialhour();
    }

    return 0;
}
