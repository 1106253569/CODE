#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <string>
#include <algorithm>

void trans(std::string &s)
{
    for (size_t p = 0; p < s.size();p++)
    {
        if (s[p]>='A'&&s[p]<='Z')
            s[p] -= ('A' - 'a');
            else if(s[p]==','||s[p]=='.'||s[p]=='!')
            {
                s.erase(p, 1);
            }
    }
}

int main()
{
    void trans(std::string & s);
    std::string argv[] = {"C:\\Users\\solitary cloud\\Documents\\practise\\sun.txt"};
    std::ifstream in(argv[0]);
    if(!in)
    {
        std::cout << "打开失败"
                  << "\n";
        exit(1);
    }
    std::map<std::string, std::list<int>> word_lineno;
    std::string line;
    std::string word;
    int lineno = 0;
    while (getline(in,line))    
    {
        lineno++;
        std::istringstream In(line);
        while (In>>word)
        {
            trans(word);
            word_lineno[word].push_back(lineno);
        }
    }
    for(const auto&w:word_lineno)
    {
        std::cout << w.first << "存在"<<(w.second).size()<<"个\t所在行:";
        for (const auto &i:w.second)
            std::cout << i << ".";
        std::cout << "\n";
    }
    return 0;
}