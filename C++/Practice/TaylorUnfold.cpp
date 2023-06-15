#include "omp.h"
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    double test(int x);
    double TaylorUnfold(int x);
    int x;
    cout << "please enter number:";
    cin >> x;
    clock_t start, end;
    start = clock();
    cout << "e^" << x << "=" << TaylorUnfold(x);
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time used: " << duration << "s" << endl;
    start = clock();
    cout << "e^" << x << "=" << test(x);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time used: " << duration << "s" << endl;
    return 0;
}

double test(int x){
    int Factorial(int x);
    int i = 0;
    double taile = 0.0;
    for (i = 0; i < 16; i++)
    {
        taile += pow(x, i) / Factorial(i);
    }
    return (taile);
}

double TaylorUnfold(int x)
{
    int Factorial(int x);
    int i = 0;
    double taile = 0.0;
#pragma omp parallel for
    for (i = 0; i < 16; i++)
    {
        taile += pow(x, i) / Factorial(i);
    }
    return (taile);
}
int Factorial(int x)
{
    int sum = 1, i;
    if (x == 0)
        sum = 1;
    else
        for (i = 1; i <= x; i++)
            sum *= i;
    return (sum);
}