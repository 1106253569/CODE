#include <iostream>
class Base
{
    friend class Pal;

public:
    Base():mem(0){}
    void pub_mem();
    

private:
    int prot_mem;

protected:
    int mem = 0;
    char priv_mem;
    int prot_mem;
};


class Sneaky:public Base
{
    friend void clobber(Sneaky &);
    friend void clobber(Sneaky &);
public:

private:
    int j;
};
void clobber(Sneaky &s)
{
    s.j = s.prot_mem = 0;
}

class Priv_Derv:private Base
{
public:
    int f1() const { return prot_mem; }
};

class Derived:public Base
{
public:
    Derived(int i):mem(i){}
    int get_mem() { return Base::mem; }
private:
    int mem = 0;
};
