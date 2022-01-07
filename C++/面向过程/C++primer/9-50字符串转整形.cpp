#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector vs = {"123", "45", "78"};
    int sum = 0;
    for (auto iter = vs.begin(); iter !=vs.end(); iter++)    
    {
        sum += std::stod(*iter);
    }
    std::cout << "和:" << sum << "\n";
    return 0;
}