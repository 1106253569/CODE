#include <math.h>
#include <omp.h>
#include <stdio.h>

#define iterations 100000000
#define nthreads 2

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
    for (i = 0; i < nthreads; i++)
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
    for (i = 1; i < nthreads; i++)
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
    double start, end;
    double result_serial, result_parallel, result_parallel2;

    // 串行计算
    start = omp_get_wtime();
    result_serial = Simpson(0, 1, iterations, f);
    end = omp_get_wtime();
    double simple_time = end - start;
    printf("串行结果：π = %f\n", result_serial);
    printf("串行时间：%fs\n", simple_time);

    // 并行计算 - 按线程私有数组划分
    start = omp_get_wtime();
    result_parallel = Simpson_parallel(0, 1, iterations, f);
    end = omp_get_wtime();
    printf("并行结果：π = %f\n", result_parallel);
    printf("并行时间：%fs\n", end - start);
    printf("加速比 (按线程私有数组划分): %f\n", simple_time / (end - start));

    // 并行计算 - 按指定变量归约
    start = omp_get_wtime();
    result_parallel2 = Simpson_parallel2(0, 1, iterations, f);
    end = omp_get_wtime();
    printf("并行结果：π = %f\n", result_parallel2);
    printf("并行时间：%fs\n", end - start);
    printf("加速比 (按指定变量归约): %f\n", simple_time / (end - start));

    return 0;
}
