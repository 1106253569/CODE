#include "Complex.h"

int main()
{
    Complex c1(1, 2), c2(3, 4);
    std::cout << c1
              << c2;
    std::cout << c1 + c2;
    std::cout << c1 + 2;
    return 0;
}
