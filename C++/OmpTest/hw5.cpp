#include <omp.h>
#include <stdio.h>

#define N 500
#define BLOCK_SIZE 100

void gauss_serial(double A[N][N], double b[N], double x[N])
{
    int i, j, k;
    double ratio;

    for (k = 0; k < N - 1; k++)
    {
        for (i = k + 1; i < N; i++)
        {
            ratio = A[i][k] / A[k][k];
            for (j = k; j < N; j++)
            {
                A[i][j] -= ratio * A[k][j];
            }
            b[i] -= ratio * b[k];
        }
    }

    for (i = N - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (j = i + 1; j < N; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

void gauss_parallel(double A[N][N], double b[N], double x[N])
{
    int i, j, k;
    double ratio;

    for (k = 0; k < N - 1; k++)
    {
#pragma omp parallel for shared(A, b) private(i, j, ratio) schedule(static, BLOCK_SIZE)
        for (i = k + 1; i < N; i++)
        {
            ratio = A[i][k] / A[k][k];
            for (j = k; j < N; j++)
            {
                A[i][j] -= ratio * A[k][j];
            }
            b[i] -= ratio * b[k];
        }
    }

#pragma omp parallel for shared(A, b, x) private(i, j) schedule(static, BLOCK_SIZE)
    for (i = N - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (j = i + 1; j < N; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

int main()
{
    double A[N][N];
    double b[N];
    double x[N];
    int i, j;

    // 初始化矩阵 A 和向量 b
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

    // 串行 Gauss 消去法
    start = omp_get_wtime();
    gauss_serial(A, b, x);
    end = omp_get_wtime();
    double serial_time = end - start;

    printf("串行 Gauss 消去法时间：%.6f秒\n", serial_time);

    // 并行 Gauss 消去法
    start = omp_get_wtime();
    gauss_parallel(A, b, x);
    end = omp_get_wtime();
    double parallel_time = end - start;

    printf("并行 Gauss 消去法时间：%.6f秒\n", parallel_time);
    printf("加速比：%.6f\n", serial_time / parallel_time);
    printf("并行效率：%.6f\n", (serial_time / parallel_time) / omp_get_max_threads());

    return 0;
}