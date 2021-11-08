#include <iostream>
template <typename T>
int binary_search(T a[], int n, const T &x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (x == x[middle])
        {
            return middle;
        }
        else if (x > a[middle])
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1;
}