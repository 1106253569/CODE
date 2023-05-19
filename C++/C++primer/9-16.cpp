#include <iostream>
#include <vector>
#include <list>
bool i_v_equal(std::vector<int>&ivec,std::list<int> &ilist)
{
    if(ilist.size()!=ivec.size())
    {
        return false;
    }
    auto ib = ilist.cbegin();
    auto ie = ilist.cend();
    auto vb = ivec.cbegin();
    for (; ib != ie;ib++,vb++)
    {
        if(*ib!=*vb)
            return false;
    }
    return true;
}

