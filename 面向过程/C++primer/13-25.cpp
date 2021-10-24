#include <iostream>
#include <string>
#include <vector>
#include <memory>
class HasPtr
{
public:
    HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0),use(new size_t(i)){}
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr &operator=(const HasPtr &);
    HasPtr &operator=(const std::string &);
    std::string &operator*();
    ~HasPtr();
    void swap(HasPtr &, HasPtr &);

private:
    std::string *ps;
    int i;
    size_t *use;

};

HasPtr &HasPtr::operator=(const HasPtr &h)
{
    ++*h.use;
    if(--*use==0)
    {
        delete ps;
        delete use;
    }
    ps = h.ps;
    i = h.i;
    use = h.use;
    return *this;
}
