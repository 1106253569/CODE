#include <iostream>
#include <vector>
#include <algorithm>
class ReadString
{
public:
    ReadString(std::istream &is=std::cin):is(is){}
    std::string operator()()
    {
        std::string line;
        if(!getline(is,line))
        {
            line = " ";
        }
        return line;
    }
    void testReadString()
    {
        ReadString rs;
        while (true)
        {
            std::string line = rs();
            if(!line.empty())
                vec.push_back(line);
                else
                    break;
        }
        
    }
    void f()
    {
        count_if(vec.begin(), vec.end(), std::bind2nd(std::greater<std::string>(), "xx"));
    }

private:
    std::istream &is;
    std::vector<std::string> vec;
};