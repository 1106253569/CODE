#include <iostream>
#include <vector>
#include <memory>

class Debug_delete
{
public:
    Debug_delete(std::ostream &s=std::cerr):os(s){}
    template<typename T>void operator()(T *p) const
    {
        os << "deleting unique_ptr"
           << "\n";
        delete p;
    }
private:
    std::ostream &os;
};

template<typename T>
class Blob
{
    template <typename It>
    Blob(It b, It e);
};

int main()
{
    double *p = new double;
    Debug_delete d;
    d(p);
    int *ip = new int;
    Debug_delete()(ip);
    std::unique_ptr<int, Debug_delete> q(new int, Debug_delete());
    std::unique_ptr<std::string, Debug_delete> sq(new std::string, Debug_delete());
    return 0;
}