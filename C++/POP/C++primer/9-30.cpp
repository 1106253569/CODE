#include <iostream>
#include <vector>
int main()
{
    std::vector<int> iv(25, 3);
    iv.resize(50);
    for(const auto a:iv)
        std::cout << a << " ";
    iv.resize(10);
    for(const auto a:iv)
        std::cout << a << " ";
    return 0;
}