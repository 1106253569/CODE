#include <iostream>
#include <vector>
struct data
{
    data() = default;
    data(int a,double c):speed(a),distance(c){}
    int speed=1;
    double distance=0;
};
int main()
{
    std::vector<data> init(int L, int n);
    void out_bounds(int L, std::vector<data> &x);
    void exercise(std::vector<data> & x,double interval);
    void crash(std::vector<data> & x);
    double interval_set(std::vector<data> & x);
    int L=0,n=0;
    std::cout << "输入总长L和小球个数n:";
    std::cin >> L >> n;
    std::cout << "注：此程序每个小球的速率应相等,仅改变方向"
              << "\n";
    std::vector<data> New=init(L, n);
    for(const auto x:New)
        if(abs(x.speed)!=abs(New[0].speed)) //判断速率是否相等
        {
            std::cout << "This enter is false"
                  << "\n";
            return 0;
        }
    double interval = interval_set(New),time=0;
    while(New.size() != 0)
    {
        exercise(New,interval);
        crash(New);
        out_bounds(L,New);
        time+=interval;
    }
    std::cout << "time=" << time;
    return 0;
}

std::vector<data> init(int L,int n) //初始化小球速度和位置
{
    std::vector<data> x;
    double d=0,sign=0;
    if(L%2==0&&n%2==0)
        d = L / n * 0.5;
    else if(L%2!=0&&n%2!=0)
        d = L / n * 0.5;
        else
            {
                d = L / n;
                sign = 1;
            }
    for (int i = 0; i < n;i++)
    {
        int v=0;
        std::cout << "输入" << i + 1 << "个小球速度:";
        std::cin >> v;  //速率必须相同
        data y;
        if(sign==0)
            {
                data temp(v, (2 * i + 1) * d);
                y=temp;
            }
        else
            {
                data temp(v, (i+1) * d);
                y = temp;
            }
        x.push_back(y);
    }
    return x;
}

void exercise(std::vector<data> &x,double interval) //球进行运动
{
    for(auto &a:x)
        a.distance += a.speed*interval;
}

void out_bounds(int L,std::vector<data> &x) //判断并清除出界球
{
    if(x.begin()->distance<0)
        x.erase(x.begin()); //删除首项
    if(x[x.size()-1].distance>L)
        x.pop_back(); //删除末项
    if(x.begin()->distance==0&&x.begin()->speed<0)
        x.erase(x.begin());
    if(x[x.size()-1].distance==L&&x[x.size()-1].speed>0)
        x.pop_back();
}

void crash(std::vector<data> &x) //判断球是否发生碰撞
{
    auto first = x.begin();
    auto second = first + 1;
    while (second!=x.end())
    {
        if(first->distance==second->distance)  //坐标相同则碰撞并速度互换
        {
            int temp=first->speed;
            first->speed = second->speed;
            second->distance = temp;
        }
        ++first;
        ++second;
    }
}

double interval_set(std::vector<data> &x) //设定产生碰撞的时间间隔
{
    double distance = (x[1].distance - x[0].distance)/2;
    double speed = abs(x[0].speed);
    double interval = distance / speed;
    return interval;
}