#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Cloud
{
    friend Cloud operator+(const Cloud &lhs,const Cloud &rhs);
    friend ostream& operator<<(std::ostream &os, const Cloud &clo);
    friend istream &operator>>(std::istream &is, Cloud &clo);

public:
    Cloud() { cout << "初始化一个Cloud()"<<"\n"; };
    Cloud(int a) : x(a) { cout << "调用构造函数：Cloud(),x=" << a << endl; }
    Cloud(int a,std::string&s):x(a),clouds(s){}
    Cloud(const Cloud& clo) 
    {
        x = clo.x;
        cout << "调用拷贝构造函数：Cloud(const Cloud&),x=" <<x << endl;
    }
    Cloud(Cloud&& clo) noexcept
    {
        x = clo.x;
        cout << "调用移动构造函数：Cloud(Cloud&&),x=" << x << endl;
    }
    Cloud& operator=(const int &i)
    {
        x = i;
        cout << "调用拷贝重载运算符operator=(const int),x=" << x << endl;
        return *this;
    }
    Cloud& operator=(Cloud &&i)
    {
        x = i.x;
        cout << "调用移动重载运算符operator=(const int&&),x=" << x << endl;
        return *this;
    }
    ~Cloud() 
    {
        if (ptr != nullptr)
            delete ptr;
        cout << "调用析构函数：~Cloud(),x=" << x << endl;
    }
    void print() { std::cout<<x<<"\n"; }
    char operator[](size_t n) { return clouds[n]; }
    Cloud& operator++()
    {
        ++x;
        return *this;
    }
    const int operator->()const
    {
        std::cout << "int operator->()const"
                  << "\n";
        return this->x;
    }
    const int* operator*() const
    {
        std::cout << "int operator*() const"
                  << "\n";
        *ptr = x;
        return ptr;
    }

private:
    int x;
    std::string clouds;
    int *ptr = nullptr;
};
Cloud operator+(const Cloud &lhs, const Cloud &rhs)
{
    Cloud temp;
    std::cout << "operator+(Cloud &lhs, Cloud &rhs)"
              << "\n";
    temp.x=lhs.x + rhs.x;
    return temp;
}
ostream& operator<<(std::ostream &os, const Cloud &clo)
{
    std::cout << "operator<<(std::ostream &, const Cloud &)"
              << "\n";
    os << clo.x<<"\n";
    return os;
}
istream& operator>>(std::istream &is,Cloud&clo)
{
    std::cout << "operator>>(std::ostream &, const Cloud &)"
              << "\n";
    int temp;
    is >> temp;
    if(is)
        clo.x = temp;
        else
            clo = Cloud();
    return is;
}

Cloud getCloud()
{
    Cloud Cloud;
    return Cloud;
}
void setCloud(Cloud&& clo)
{
    std::cout << "右值引用"
              << "\n";

    std::cout << clo;
    std::cin >> clo;
    std::cout << clo;
}

int main(int argc, char **argv)
{
    std::vector<Cloud> vec;
    Cloud z;
    vec.reserve(256);
    int i = 0;
    cout << "存放在容器：" << endl;
    while(i<4)
    {
        z = i;
        vec.push_back(std::move(z));
        i++;
    }
    cout << endl;
    setCloud(getCloud());
    cout << *vec[3] ;
    cout << "\n";
    cout << "程序结束！！！" << endl;
    return 0;
}