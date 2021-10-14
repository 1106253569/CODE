#include <iostream>
#include <vector>
int main()
{
    std::vector<int> ilist1;
    std::vector<int> ilist2(ilist1);
    std::vector<int> ilist = {1, 2, 3, 0, 4, 5, 6, 7};
    std::vector<int> ilist3(ilist.begin() + 2, ilist.end() - 1);
    std::vector<int> ilist4(7);
    std::vector<int> ilist5(7, 3);
    return 0;
}