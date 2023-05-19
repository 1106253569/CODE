#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
std::istream & f(std::istream &in)
{
    std::string v;
    while (in>>v,!in.eof())
    {
        if(in.bad())
            throw std::runtime_error("IO流错误");
        if(in.fail())
        {
            std::cerr << "数据错误，请重试："
                 << "\n";
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        std::cout << v << "\n";
    }
    in.clear();
    return in;
}

int main()
{
    std::ostringstream msg;
    msg << "《C++primer》第五版"
        << "\n";
    msg << "输入一些整数，按Ctrl+Z结束"
              << "\n";
    std::istringstream in(msg.str());
    f(in);
    f(std::cin);
    return 0;
}