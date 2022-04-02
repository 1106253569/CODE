#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 3;
    int b = 4;
    swap(a, b);
    std::cout << a << "," << b << '\n';
    return 0;
}