#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

std::string format(const std::string&s)
{
    return s;
}

bool valid(const std::string &s)
{
    return true;
}

int main(int argc,char *argv[])
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    if(argc!=2)
    {
        std::cerr << "请给出文件名"
                  << "\n";
        return -1;
    }
    std::ifstream in(argv[1]);
    if(!in)
    {
        std::cerr << "无法打开输入文件"
                  << "\n";
        return -1;
    }
    while (getline(std::cin,line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record>>word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    std::ostringstream os;
    for(const auto &entry:people)
    {
        std::ostringstream formatted, badNums;
        for(const auto &nums:entry.phones)
        {
            if(!valid(nums))
                badNums << " "
                        << nums;
            else
                formatted << " " << format(nums);
        }
        if(badNums.str().empty())
            os << entry.name << " " << formatted.str() << "\n";
            else
                std::cerr << "input error:" << entry.name << "invalid number(s)" << badNums.str() << "\n";
    }
    std::cout << os.str() << "\n";
    return 0;
}
