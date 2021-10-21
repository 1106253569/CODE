#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
int main()
{
    int argv;
    std::string argc = "D:\\Visual Studio\\CODE\\PractiseDocument\\sun.txt ";
    std::ifstream in(argc);
    if(!in)
    {
        std::cout << "打开输入文件失败"
                  << "\n";
        exit(1);
    }
    std::string line;
    std::vector<std::string> words;
    while (getline(in,line))
    {
        words.push_back(line);
    }
    in.close();
    argv = words.size();
    for(auto &c:words)
        std::cout << c << "\n";
    std::cout << argv<< "\n";
    return 0;
}