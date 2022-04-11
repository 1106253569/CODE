#include <iostream>
using namespace std;
void fac(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}