#include <iostream>
#include <cstring>
int main()
{
    const char *c1 = "Hello";
    const char *c2 = "World";
    char *r = new char[strlen(c1) + strlen(c2) + 1];
    strcpy(r, c1);
    strcat(r, c2);
    std::cout << r << "\n";
    std::string s1 = "hello";
    std::string s2 = "world";
    strcpy(r, (s1 + s2).c_str());
    std::cout << r << "\n";
    delete[] r;
    return 0;
}