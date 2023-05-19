#include <iostream>
#include <string>
#include <vector>
#include <list>

template<typename I,typename T>
I find(I b,I e,const T &v)
{
    while (b!=e&&b!=v)
    {
        b++;
    }
    return b;
}

int main()
{
    std::vector<int> v1 = {0, 1, 2, 3, 4, 5, 6};
    std::list<std::string> ls = {"hello", "world", "!"};
    return 0;
}