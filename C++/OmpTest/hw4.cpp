#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 500
#define MAX_ITER 100
#define EPSILON 1e-6

void jacobi_serial(double A[N][N], double b[N], double x[N])
{
    int i, j, iter;
    double x_new[N];
    double sum;

    for (iter = 0; iter < MAX_ITER; iter++)
    {
        for (i = 0; i < N; i++)
        {
            sum = b[i];
            for (j = 0; j < N; j++)
            {
                if (i != j)
                {
                    sum -= A[i][j] * x[j];
                }
            }
            x_new[i] = sum / A[i][i];
        }

        int converged = 1;
        for (i = 0; i < N; i++)
        {
            if (fabs(x_new[i] - x[i]) > EPSILON)
            {
                converged = 0;
                break;
            }
        }

        if (converged)
        {
            break;
        }

        for (i = 0; i < N; i++)
        {
            x[i] = x_new[i];
        }
    }
}

void gauss_seidel_serial(double A[N][N], double b[N], double x[N])
{
    int i, j, iter;
    double sum;

    for (iter = 0; iter < MAX_ITER; iter++)
    {
        for (i = 0; i < N; i++)
        {
            sum = b[i];
            for (j = 0; j < N; j++)
            {
                if (i != j)
                {
                    sum -= A[i][j] * x[j];
                }
            }
            x[i] = sum / A[i][i];
        }

        int converged = 1;
        for (i = 0; i < N; i++)
        {
            sum = b[i];
            for (j = 0; j < N; j++)
            {
                sum -= A[i][j] * x[j];
            }
            if (fabs(sum) > EPSILON)
            {
                converged = 0;
                break;
            }
        }

        if (converged)
        {
            break;
        }
    }
}

void jacobi_parallel(double A[N][N], double b[N], double x[N])
{
    int i, j, iter;
    double x_new[N];
    double sum;

    for (iter = 0; iter < MAX_ITER; iter++)
    {
#pragma omp parallel for private(j, sum) shared(A, b, x, x_new)
        for (i = 0; i < N; i++)
        {
            sum = b[i];
            for (j = 0; j < N; j++)
            {
                if (i != j)
                {
                    sum -= A[i][j] * x[j];
                }
            }
            x_new[i] = sum / A[i][i];
        }

        int converged = 1;
        for (i = 0; i < N; i++)
        {
            if (fabs(x_new[i] - x[i]) > EPSILON)
            {
                converged = 0;
                break;
            }
        }

        if (converged)
        {
            break;
        }

        for (i = 0; i < N; i++)
        {
            x[i] = x_new[i];
        }
    }
}

void gauss_seidel_parallel(double A[N][N], double b[N], double x[N])
{
    int i, j, iter;
    double sum;

    for (iter = 0; iter < MAX_ITER; iter++)
    {
#pragma omp parallel for private(j, sum) shared(A, b, x)
        for (i = 0; i < N; i++)
        {
            sum = b[i];
            for (j = 0; j < N; j++)
            {
                if (i != j)
                {
                    sum -= A[i][j] * x[j];
                }
            }
            x[i] = sum / A[i][i];
        }

        int converged = 1;
#pragma omp parallel for private(j, sum) shared(A, b, x) reduction(&& : converged)
        for (i = 0; i < N; i++)
        {
            sum = b[i];
            for (j = 0; j < N; j++)
            {
                sum -= A[i][j] * x[j];
            }
            if (fabs(sum) > EPSILON)
            {
                converged = 0;
            }
        }

        if (converged)
        {
            break;
        }
    }
}

int main()
{
    double A[N][N];
    double b[N];
    double x[N];
    int i, j;

    // Initialize matrix A and vector b
    for (i = 0; i < N; i++)
    {
        b[i] = 1.0;
        x[i] = 0.0;
        for (j = 0; j < N; j++)
        {
            if (i == j)
                A[i][j] = 2.0;
            else
                A[i][j] = 1.0;
        }
    }

    double start, end;

    // Serial Jacobi iteration
    start = omp_get_wtime();
    jacobi_serial(A, b, x);
    end = omp_get_wtime();
    double serial_time_jacobi = end - start;
    printf("串行Jacobi迭代时间: %.6f秒\n", serial_time_jacobi);

    // Serial Gauss-Seidel iteration
    start = omp_get_wtime();
    gauss_seidel_serial(A, b, x);
    end = omp_get_wtime();
    double serial_time_gauss_seidel = end - start;
    printf("串行Gauss-Seidel迭代时间: %.6f秒\n", serial_time_gauss_seidel);

    // Parallel Jacobi iteration
    start = omp_get_wtime();
    jacobi_parallel(A, b, x);
    end = omp_get_wtime();
    double parallel_time_jacobi = end - start;
    printf("并行Jacobi迭代时间: %.6f秒\n", parallel_time_jacobi);
    printf("加速比：%.6f\n", serial_time_jacobi / parallel_time_jacobi);
    printf("并行效率：%.6f\n", (serial_time_jacobi / parallel_time_jacobi) / omp_get_max_threads());

    // Parallel Gauss-Seidel iteration
    start = omp_get_wtime();
    gauss_seidel_parallel(A, b, x);
    end = omp_get_wtime();
    double parallel_time_gauss_seidel = end - start;
    printf("并行Gauss-Seidel迭代时间: %.6f秒\n", parallel_time_gauss_seidel);
    printf("加速比：%.6f\n", serial_time_gauss_seidel / parallel_time_gauss_seidel);
    printf("并行效率：%.6f\n", (serial_time_gauss_seidel / parallel_time_gauss_seidel) / omp_get_max_threads());

    return 0;
}
