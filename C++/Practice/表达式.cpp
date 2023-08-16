#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) { return a + b; }

int main()
{
    int example;
    example = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    cout << example << endl;
    example = -30 * 3 + 21 / 5;
    cout << example << endl;
    return 0;
}