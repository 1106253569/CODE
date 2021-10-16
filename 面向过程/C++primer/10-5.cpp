#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
int main()
{
    char argv[] ="C:\\Users\\solitary cloud\\Downloads\\sun.txt";
    std::ifstream in(argv);
    if(!in)
    {
        std::cout << "打开输入文件失败"
                  << "\n";
        exit(1);
    }
    std::vector<char> vi;
    char val;
    while (in>>val)
    {
        vi.push_back(val);
        std::cout << val ;
    }
    std::cout << "\n";
    fill_n(vi.begin(), vi.size(), 'x');
    for (auto iter = vi.begin(); iter != vi.end();iter++)
    {
        std::cout << *iter << " ";
    }
    return 0;
}