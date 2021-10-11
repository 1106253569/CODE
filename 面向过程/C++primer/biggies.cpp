#include <iostream>
#include <vector>
void biggies(std::vector<std::string> &words,
            std::vector<std::string>::size_type sz)
{
    auto a = [](const std::string &a, const std::string &b)
    { return a.size() < b.size(); };
}