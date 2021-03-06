#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
int main()
{
    std::istream_iterator<int> in_iter(std::cin);
    std::istream_iterator<int> eof;
    std::vector<int> vi;
    while (in_iter!=eof)
    {
        vi.push_back(*in_iter++);    
    }
    std::sort(vi.begin(), vi.end());
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::unique_copy(vi.begin(), vi.end(), out_iter);
    return 0;
}