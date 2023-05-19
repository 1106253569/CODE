#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
int main()
{
    void print(std::list<int> & li);
    std::vector<int> vi = {1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    std::list<int> li1, li2, li3;
    std::unique_copy(vi.begin(), vi.end(), std::inserter(li1,li1.begin()));
    print(li1);
    std::unique_copy(vi.begin(), vi.end(), std::back_inserter(li2));
    print(li2);
    std::unique_copy(vi.begin(), vi.end(), std::front_inserter(li3));
    print(li3);
    return 0;
}

void print(std::list<int> &li)
{
    for(auto v:li)
        std::cout << v << " ";
    std::cout << "\n";
}