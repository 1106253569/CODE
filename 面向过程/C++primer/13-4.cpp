#include <iostream>
#include <vector>
struct X
{
    X() { std::cout << "构造函数X()"
                    << "\n"; }
    X(const X &) { std::cout << "拷贝构造函数X(const X&)"
                             << "\n"; }
    X(X &&) { std::cout << "移动构造函数X(const X&)"
                             << "\n"; }
    X &operator=(const X &rhs) 
    {
        std::cout << "拷贝赋值运算符=(const X&)"
                  << "\n";
        return *this;
    }
    X &operator()(const X &rhs) 
    {
        std::cout << "重置运算符=(const X&&)"
                  << "\n";
        return *this;
    }
    ~X() { std::cout << "析构函数~X()"
                     << "\n"; }
                     
};

void f1(X x)
{

}

void f2(X &x)
{

}
int main()
{
    std::cout << "局部变量；"
              << "\n";
    X x;
    std::cout << "\n";
    std::cout << "非引用参数列表传递："
              << "\n";
    f1(x);
    std::cout << "\n";
    std::cout << "引用参数传递:"
              << "\n";
    f2(x);
    std::cout << "\n";
    std::cout << "动态分配:"
              << "\n";
    X *px = new X;
    std::cout << "\n";
    std::cout << "释放动态分配对象："
              << "\n";
    delete px;
    std::cout << "\n";
    std::cout << "间接初始化和赋值："
              << "\n";
    X y = x;
    y = x;
    std::cout << "\n";
    std::cout << "添加到容器中："
              << "\n";
    std::vector<X> vx;
    for (int i = 0; i < 8;i++)
    {
        X z;
        x(z);
        vx.push_back(x);
    }
    std::cout << "\n";
    std::cout << "函数赋值"
              << "\n";
    for (int i = 0; i < 8;i++)
    {
        X z;
        x(z);
    }
    std::cout << "程序结束："
              << "\n";
    return 0;
}