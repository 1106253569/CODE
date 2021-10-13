#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
int main()
{
    std::ifstream in("C:\\Users\\solitary cloud\\Downloads\\hamlet.txt"); //文件名
    if(!in)
    {
        std::cerr << "无法打开输入文件"
                  << "\n";
        return -1;
    }
    std::string line;
    std::vector<std::string> words;
    while (getline(in,line))
    {
        words.push_back(line);
    }
    in.close();
    std::vector<std::string>::const_iterator it = words.begin();
    while (it!=words.end())
    {
        std::istringstream line_str(*it);
        std::string word;
        while (line_str>>word)
        {
            std::cout << word << " ";
        }
        std::cout << "\n";
        ++it;
    }
    return 0;
}