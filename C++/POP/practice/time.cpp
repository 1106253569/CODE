#include <iostream>
#include <vector>
class Time
{
    friend std::istream &operator>>(std::istream &is, Time &T);
    friend std::ostream &operator<<(std::ostream &os, Time &T);
    friend Time &check(Time &);

private:
    int hour = 0;
    int minute = 0;
    int second = 0;

public:
    Time() = default;
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
    Time(Time &T) : hour(T.hour), minute(T.minute), second(T.second) {} //拷贝初始化
    Time &operator=(const Time &T)                                      //拷贝重载运算符
    {
        hour = T.hour, minute = T.minute, second = T.second;
        return *this;
    }
    Time &operator+=(const Time &);
    Time &operator-=(const Time &);
    Time &operator++();
    Time operator++(int);
    Time &operator--();
    Time operator--(int);
    ~Time() = default;
};
Time &check(Time &T) //检查参数是否超出范围，对超出范围的数进行修正
{
    if (T.second >= 60)
    {
        T.second = T.second % 60;
        T.minute++;
    }
    else if (T.second < 0)
    {
        T.second = 60 + T.second;
        T.minute--;
    }
    if (T.minute >= 60)
    {
        T.minute = T.minute % 60;
        T.hour++;
    }
    else if (T.minute < 0)
    {
        T.minute = 60 + T.minute;
        T.hour--;
    }
    if (T.hour >= 24)
        T.hour = T.hour % 24;
    else if (T.hour < 0)
        T.hour = 24 + T.hour;
    return T;
}
std::istream &operator>>(std::istream &is, Time &T)
{
    int h, m, s;
    is >> h >> m >> s;
    if (0 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60)
    {
        Time New_time(h, m, s);
        T = New_time;
    }
    else
        std::cout << "输入错误"
                  << "\n";
    return is;
}
std::ostream &operator<<(std::ostream &os, Time &T) //输出，在数字小于10时前置一个0
{
    if (T.hour < 10)
        os << "0" << T.hour << ":";
    else
        os << T.hour << ":";
    if (T.minute < 10)
        os << "0" << T.minute << ":";
    else
        os << T.minute << ":";
    if (T.second < 10)
        os << "0" << T.second << "\n";
    else
        os << T.second << "\n";
    return os;
}
Time &Time::operator+=(const Time &T)
{
    this->hour += T.hour;
    this->minute += T.minute;
    this->second += T.second;
    *this = check(*this);
    return *this;
}
Time &Time::operator-=(const Time &T)
{
    this->hour -= T.hour;
    this->minute -= T.minute;
    this->second -= T.second;
    *this = check(*this);
    return *this;
}
Time &Time::operator++()
{
    ++this->second;
    if (this->second == 60)
    {
        this->second = 00;
        ++this->minute;
    }
    if (this->minute == 60)
    {
        this->minute = 00;
        ++this->hour;
    }
    if (this->hour == 24)
        this->hour = 00;
    return *this;
}
Time Time::operator++(int)
{
    Time temp(*this);
    ++*this;
    return temp;
}

Time &Time::operator--()
{
    --this->second;
    if (this->second == 00)
    {
        this->second = 59;
        --this->minute;
    }
    if (this->minute == 00)
    {
        this->minute = 59;
        --this->hour;
    }
    if (this->hour == 00)
        this->hour = 23;
    return *this;
}
Time Time::operator--(int)
{
    Time temp(*this);
    --*this;
    return temp;
}

int main()
{
    Time time1, time2;
    std::cin >> time1 >> time2;
    time1 += (time2++);
    std::cout << time1;
    time1 -= time2;
    std::cout << time1;
    ++time2;
    std::cout << time2;
    time2 += (time1--);
    std::cout << time2;
    --time1;
    std::cout << time1;
    time2 -= time1;
    std::cout << time2;
    return 0;
}
