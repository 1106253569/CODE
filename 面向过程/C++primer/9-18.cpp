#include <iostream>
#include <deque>
#include <list>
int main()
{
    std::deque<std::string> sd;
    std::string word;
    while (std::cin>>word)
    {
        sd.push_back(word);
    }
    for (auto si = sd.cbegin(); si != sd.cend();si++)
    {
        std::cout << *si << "\n";
    }
    std::list<std::string> sl;
    std::string word1;
    while (std::cin>>word1)
    {
        sl.push_back(word1);
    }
    for (auto si = sl.cbegin(); si != sl.cend();si++)
    {
        std::cout << *si << "\n";
    }
    return 0;
}