#include <iostream>
#include <string>
#include <vector>
#include <memory>
std::shared_ptr<std::vector<int>> new_vector(void)
{
    return std::make_shared<std::vector<int>>();
}

void read_ints(std::shared_ptr<std::vector<int>> pv)
{
    int v;
    while (std::cin>>v)
    {
        pv->push_back(v);
    }
}

void print_ints(std::shared_ptr<std::vector<int>> pv)
{
    for(const auto &v:*pv)
        std::cout << v << " ";
    std::cout << "\n";
}

int main()
{
    auto pv = new_vector();
    read_ints(pv);
    print_ints(pv);
    std::cout << (*pv).size();
    return 0;
}