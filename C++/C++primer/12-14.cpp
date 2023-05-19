#include <iostream>
#include <vector>
#include <memory>

struct destination{};
struct connection{};

connection connect(destination *pd)
{
    std::cout << "打开链接"
              << "\n";
    return connection();
}
void disconnect(connection c)
{
    std::cout << "关闭链接"
              << "\n";
}

//未使用shared_ptr版本
void f(destination &d)
{
    std::cout << "直接管理connect"
              << "\n";
    connection c = connect(&d);
    std::cout << "\n";
}

void end_connection(connection *p)
{
    disconnect(*p);
}

void f1(destination &d)
{
    std::cout << "用shared_prt管理connect"
              << "\n";
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, [](connection *p) -> void
                                  { disconnect(*p); });
    std::cout << "\n";
}
int main()
{
    destination d;
    f(d);
    f1(d);
    return 0;
}