#include <iostream>
#include <vector>

std::vector<int>::iterator search_vec(std::vector<int>::iterator beg,std::vector<int>::iterator end,int val)
{
    for (; beg != end;beg++)
        if(*beg==val)
            return beg;
    return end;
}

int main()
{
    std::vector<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    std::cout << search_vec(ilist.begin(), ilist.end(), 3)-ilist.begin() << "\n";
    std::cout << search_vec(ilist.begin(), ilist.end(), 8)-ilist.begin() << "\n";
    return 0;
}