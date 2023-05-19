#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

void add_family(std::map<std::string,std::vector<std::string>>&families,const std::string &family)
{
    if(families.find(family)==families.end())
        families[family] = std::vector<std::string>();
}
void add_child(std::map<std::string,std::vector<std::string>>&families,const std::string &family,const std::string &name)
{
    families[family].push_back(name);
}

int main()
{
    void add_family(std::map<std::string, std::vector<std::string>> & families, const std::string &family);
    void add_child(std::map<std::string, std::vector<std::string>> & families, const std::string &family, const std::string &name);
    std::map<std::string, std::vector<std::string>> families;
}