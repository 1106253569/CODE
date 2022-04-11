#include <iostream> 
class Employee
{
    friend void f(const Employee &);

public:
    Employee() { mysn = seq++; }
    Employee(std::string &s) : name(s) { mysn = seq++; }
    Employee(const Employee &n) { mysn = seq++; }
    Employee& operator=(Employee  &s)
    {
        name = s.name;
        mysn = seq++;
        return *this;
    }

private:
    int mysn;
    static int seq;
    std::string name;

};
int Employee::seq = 0;

void f(const Employee &s)
{
    std::cout << s.mysn << "\n";
}

int main()
{
    Employee a, b = a, c = b;
    f(a), f(b), f(c);
    return 0;
}