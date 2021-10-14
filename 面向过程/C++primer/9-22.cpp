#include <iostream>
#include <vector>
int main()
{
    std::vector<int> iv = {1, 1, 2, 1};
    int some_val=1;
    auto iter = iv.begin();
    int org_size = iv.size(), new_ele = 0;
    while (iter!=(iv.begin()+org_size/2+new_ele))
    {
        if(*iter==some_val)
        {
            iter = iv.insert(iter, 2 * some_val);
            new_ele++;
            iter += 2;
        }
        else
            iter++;
    }
    for (iter = iv.begin(); iter != iv.end();iter++)
        std::cout << *iter << "\n";
    return 0;
}