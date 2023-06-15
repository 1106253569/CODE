#include <math.h>
#include <omp.h>
#include <stdio.h>

#define iterations 10000000
#define nthreads 16

double Simpson(double a, double b, int n, double (*f)(double x))
{
    double h = (b - a) / n;
    double sum1 = 0, sum2 = 0;
    int i;
    for (i = 1; i <= n - 1; i += 2)
        sum1 += f(a + i * h);
    for (i = 2; i <= n - 2; i += 2)
        sum2 += f(a + i * h);
    return h / 3 * (f(a) + 4 * sum1 + 2 * sum2 + f(b));
}
double Simpson_parallel(double a, double b, int n, double (*f)(double x))
{
    double sum1[nthreads];
    double sum2[nthreads];
    double h = (b - a) / n;
    int tid;
    int i;
    for (int i = 0; i < nthreads; i++)
    {
        sum1[i] = 0;
        sum2[i] = 0;
    }
#pragma omp parallel num_threads(nthreads) private(i, tid) shared(a, b, h, sum1, sum2)
    {
        tid = omp_get_thread_num();
#pragma omp for
        for (i = 1; i <= n - 1; i += 2)
            sum1[tid] += f(a + i * h);
        for (i = 2; i <= n - 2; i += 2)
            sum2[tid] += f(a + i * h);
    }
    for (int i = 1; i < nthreads; i++)
    {
        sum1[0] += sum1[i];
        sum2[0] += sum2[i];
    }
    return h / 3 * (f(a) + 4 * sum1[0] + 2 * sum1[0] + f(b));
}
double Simpson_parallel2(double a, double b, int n, double (*f)(double x))
{
    double h = (b - a) / n;
    double sum1 = 0, sum2 = 0;
    int i, tid;
#pragma omp parallel num_threads(nthreads) reduction(+ : sum1, sum2) private(i, tid) shared(a, b, h)
    {
        tid = omp_get_thread_num();
#pragma omp for
        for (i = 1; i <= n - 1; i += 2)
            sum1 += f(a + i * h);
        for (i = 2; i <= n - 2; i += 2)
            sum2 += f(a + i * h);
    }
    return h / 3 * (f(a) + 4 * sum1 + 2 * sum1 + f(b));
}
double f(double x)
{
    return (4 / (1 + x * x));
}
int main()
{
    double start = omp_get_wtime();
    double result1 = Simpson(0, 1, iterations, f);
    double end = omp_get_wtime();
    printf("串行结果：π = %f\n", result1);
    printf("串行时间：%fs\n", end - start);
    start = omp_get_wtime();
    double result2 = Simpson_parallel(0, 1, iterations, f);
    end = omp_get_wtime();
    printf("并行结果：π = %f\n", result2);
    printf("并行时间：%fs\n", end - start);
    start = omp_get_wtime();
    double result3 = Simpson_parallel2(0, 1, iterations, f);
    end = omp_get_wtime();
    printf("并行结果：π = %f\n", result3);
    printf("并行时间：%fs\n", end - start);
    return 0;
}
