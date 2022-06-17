#include <iostream>
#include <string>
#include <type_traits>
template <typename T>
std::string debug_rep(const T &t)
{
    printf("debug_rep(const T& t)");
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
std::string debug_rep(T *p)
{
    printf("debug_rep(T *p)");
    std::ostringstream ret;
    ret << "pointer:" << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << "null pointer";
    return ret.str();
}

std::string debug_rep(const std::string &s)
{
    return '"' + s + '"';
}

std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}

template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &...rest)
{
    os << t << ",";
    return print(os, rest...);
}

int main()
{
    std::string s("hi");
    std::cout << debug_rep(s) << "\n";
    std::cout << debug_rep(&s) << "\n";
    const std::string *sp = &s;
    std::cout << debug_rep(sp) << "\n";
    return 0;
}