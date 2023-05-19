#include <iostream>
#include <vector>
#include <list>
int main()
{
    std::list<char *> slist = {"Hello", "world", "!"};
    std::vector<std::string> svec;
    svec.assign(slist.begin(), slist.end());
    std::cout << svec.capacity() << " " << svec.size() << " " 
    << svec[0] << " " << svec[svec.size() - 1] << "\n";
    return 0;
}