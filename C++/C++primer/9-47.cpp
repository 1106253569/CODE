#include <iostream>
#include <string>
void find_char(std::string &s,const std::string &chars )
{
    std::cout << "在" << s << "查找" << chars << "中字符"
              << "\n";
    std::string::size_type pos = 0;
    while((pos=s.find_first_of(chars,pos))!=std::string::npos)
    {
        std::cout << "pos: " << pos << ",char: " << s[pos] << "\n";
        pos++;
    }
}

int main()
{
    std::string s = "ab2c3d7R4E6";
    std::cout << "查找所有数字"
              << "\n";
    find_char(s, "0123456789");
    std::cout << "\n"
              << "查找所有字母"
              << "\n";
    find_char(s, "abcdefghigklmnopqrstuvwxyz");
    return 0;
}