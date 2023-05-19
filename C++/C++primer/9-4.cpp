#include <iostream>
#include <vector>

bool search_vec(std::vector<int>::iterator beg,std::vector<int>::iterator end,int val)
{
    for (; beg != end;beg++)
        if(*beg==val)
            return true;
    return false;
}

int main()
{
    std::vector<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    std::cout << search_vec(ilist.begin(), ilist.end(), 3) << "\n";
    std::cout << search_vec(ilist.begin(), ilist.end(), 8) << "\n";
    return 0;
}