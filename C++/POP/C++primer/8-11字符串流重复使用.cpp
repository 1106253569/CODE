#include <iostream>
#include <sstream>
#include <string>
#include <vector>
struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
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
    for (auto a : people)
        std::cout << a.name << "\n";
    return 0;
}
