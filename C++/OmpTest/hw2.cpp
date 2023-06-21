#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000000
#define NUM_THREADS 4
#define BLOCK_SIZE 100

void matrix_vector_multiply_serial(double A[N][N], double x[N], double y[N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        y[i] = 0;
        for (j = 0; j < N; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
}

void matrix_vector_multiply_parallel_row_block(double A[N][N], double x[N], double y[N])
{
    int i, j, k;

#pragma omp parallel for private(i, j, k) shared(A, x, y) num_threads(NUM_THREADS)
    for (i = 0; i < N; i += BLOCK_SIZE)
    {
        for (j = 0; j < N; j++)
        {
            for (k = i; k < i + BLOCK_SIZE; k++)
            {
                y[k] += A[k][j] * x[j];
            }
        }
    }
}

void matrix_vector_multiply_parallel_row_cyclic(double A[N][N], double x[N], double y[N])
{
    int i, j, k;

#pragma omp parallel for private(i, j, k) shared(A, x, y) num_threads(NUM_THREADS)
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
}

void matrix_vector_multiply_parallel_col_block(double A[N][N], double x[N], double y[N])
{
    int i, j, k;

#pragma omp parallel for private(i, j, k) shared(A, x, y) num_threads(NUM_THREADS)
    for (j = 0; j < N; j += BLOCK_SIZE)
    {
        for (i = 0; i < N; i++)
        {
            for (k = j; k < j + BLOCK_SIZE; k++)
            {
                y[i] += A[i][k] * x[k];
            }
        }
    }
}

int main()
{
    double A[N][N];
    double x[N];
    double y[N];
    int i, j;

    // 初始化矩阵 A 和向量 x
    for (i = 0; i < N; i++)
    {
        x[i] = 1.0;
        for (j = 0; j < N; j++)
        {
            A[i][j] = 1.0;
        }
    }

    // 串行程序
    double start_time = omp_get_wtime();
    matrix_vector_multiply_serial(A, x, y);
    double end_time = omp_get_wtime();
    double serial_time = end_time - start_time;
    printf("串行计算时间: %f 秒\n", serial_time);

    // 并行程序 - 按行块划分
    start_time = omp_get_wtime();
    matrix_vector_multiply_parallel_row_block(A, x, y);
    end_time = omp_get_wtime();
    double row_block_time = end_time - start_time;
    printf("按行块划分计算时间: %f 秒\n", row_block_time);
    printf("加速比 (按行块划分): %f\n", serial_time / row_block_time);
    printf("并行效率 (按行块划分): %f\n", (serial_time / row_block_time) / NUM_THREADS);

    // 并行程序 - 按行卷帘划分
    start_time = omp_get_wtime();
    matrix_vector_multiply_parallel_row_cyclic(A, x, y);
    end_time = omp_get_wtime();
    double row_cyclic_time = end_time - start_time;
    printf("按行卷帘划分计算时间: %f 秒\n", row_cyclic_time);
    printf("加速比 (按行卷帘划分): %f\n", serial_time / row_cyclic_time);
    printf("并行效率 (按行卷帘划分): %f\n", (serial_time / row_cyclic_time) / NUM_THREADS);

    // 并行程序 - 按列块划分
    start_time = omp_get_wtime();
    matrix_vector_multiply_parallel_col_block(A, x, y);
    end_time = omp_get_wtime();
    double col_block_time = end_time - start_time;
    printf("按列块划分计算时间: %f 秒\n", col_block_time);
    printf("加速比 (按列块划分): %f\n", serial_time / col_block_time);
    printf("并行效率 (按列块划分): %f\n", (serial_time / col_block_time) / NUM_THREADS);

    return 0;
}
