#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
int main()
{
    std::string argv[]={"C:\\Users\\solitary cloud\\Documents\\practise\\sun.txt"};
    std::ifstream in(argv[0]);
    if(!in)
    {
        throw "fail";
        exit(1);
    }
    std::map<std::string, size_t> word_count;
    std::string word;
    while(in>>word)
    {
        ++word_count[word];
    }
    for(const auto& w:word_count)
        std::cout << w.first << "出现了" << w.second << "次"
                  << "\n";
    return 0;
}