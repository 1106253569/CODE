#include <iostream>
int main()
{
    double new_tempstr;
    std::string tempstr;
    std::cout << "输入温度：";
    while(std::cin >> tempstr)
    {
    if(tempstr[tempstr.size()-1]=='F')
    {
        new_tempstr = (atoi(tempstr.c_str()) - 32) / 1.8;
        std::cout << "转换后的温度为："<<new_tempstr << 'C' << "\n";
    }
    else if(tempstr[tempstr.size()-1]=='C')
    {
        new_tempstr = atoi(tempstr.c_str()) * 1.8 + 32;
        std::cout << "转换后的温度为："<<new_tempstr << 'F' << "\n";
    }
    else
        std::cout << "输入格式错误"
                  << "\n";
        std::cout << "输入温度：";
    }
    return 0;
}