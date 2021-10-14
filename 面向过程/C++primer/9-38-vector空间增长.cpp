#include <iostream>
#include <vector>
int main()
{
    std::vector<int> vi;
    int s, c;
    while (vi.size()<=100)
    {
        for (s = vi.size(), c = vi.capacity(); s <= c;s++)
            vi.push_back(1);
        std::cout << "capacity=" << vi.capacity() << "\t"
                  << "size=" << vi.size() << "\n";
    }
    return 0;
}
