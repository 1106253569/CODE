#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
int main()
{
    std::list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 0, 8, 9};
    auto last_z = find(li.rbegin(), li.rend(), 0);
    std::cout << *last_z<<"\n";
    std::cout << *(last_z.base()) << "\n";
    last_z++;
    size_t p = 1;
    for (auto iter = li.begin(); iter != last_z.base();iter++,p++)
        ;
    if(p>=li.size())
        std::cout << "容器中没有0"
                  << "\n";
                else
                    std::cout << "last '0' in " << p << "\n";
    return 0;
}