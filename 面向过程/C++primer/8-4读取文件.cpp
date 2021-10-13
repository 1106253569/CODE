#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main()
{
    std::ifstream in("data");
    if(!in)
    {
        std::cerr << "无法打开输入文件"
                  << "\n";
        return -1;
    }
    std::string line;
    std::vector<std::string> words;
    while (getline(in,line)) //更换为while(in>>line)即可逐个单词输入
    {
        words.push_back(line);
    }
    in.close();
    std::vector<std::string>::const_iterator it = words.begin();
    while (it != words.end())
    {
        std::cout << *it << "\n";
        ++it;
    }
    return 0;
}