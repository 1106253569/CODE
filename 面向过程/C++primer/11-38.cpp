#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

std::unordered_map<std::string,std::string> buildMap(std::ifstream &map_file)
{
    std::unordered_map<std::string, std::string> trans_map;
    std::string key;
    std::string value;
    while (map_file>>key&&getline(map_file,value))
    {
        if(value.size()>1)
            trans_map[key] = value.substr(1);
            else
                throw std::runtime_error("no rule for" + key);
    }
    return trans_map;
}

const std::string& transform(const std::string &s,const std::unordered_map<std::string,std::string>& m)
{
    auto map_it = m.find(s);
    if(map_it!=m.cend())
        return map_it->second;
        else
            return s;
}

void word_transform(std::ifstream &map_file,std::ifstream input)
{
    std::unordered_map<std::string, std::string> buildMap(std::ifstream & map_file);
    auto trans_map = buildMap(map_file);
    std::cout << "Here is our transformation map:\n\n";
    for(auto entry:trans_map)
        std::cout << "kep:" << entry.first
                  << "\tvalue" << entry.second << "\n";
    std::cout << "\n\n";
    std::string text;
    while(getline(input,text))
    {
        std::istringstream stream(text);
        std::string word;
        bool firstword = true;
        while (stream>>word)
        {
            if(firstword)
                firstword = false;
                else
                    std::cout << " ";
                std::cout << transform(word, trans_map);
        }
        std::cout << "\n";
    }
}
