#include <iostream>
#include <vector>
#include <algorithm>
class Foo
{
private:
    std::vector<int> data;

public:
    Foo()=default;
    Foo(int i)
    {
        while (i!=0)
        {
            data.push_back(i);
            i--;
        }
    }
    Foo sorted() &&
    {
        std::cout << "右值版本"
                  << "\n";
        std::sort(data.begin(), data.end());
        return *this;
    }
    Foo sorted() const &
    {
        std::cout << "左值版本"
                  << "\n";
        Foo ret(*this);
        return ret.sorted();
    }
};

int main()
{
    Foo f(10);
    f.sorted();
    return 0;
}
