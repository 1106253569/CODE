#include <omp.h>
#include <stdio.h>

#define N 200
#define M 200
#define P 200
#define BLOCK_SIZE 10
#define NUM_THREAD 4

void matrix_multiply_serial(double A[N][M], double B[M][P], double C[N][P])
{
    int i, j, k;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < P; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < M; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_parallel_rows(double A[N][M], double B[M][P], double C[N][P])
{
    int i, j, k;
    omp_set_num_threads(NUM_THREAD);
#pragma omp parallel for private(i, j, k) shared(A, B, C) schedule(static, BLOCK_SIZE)
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < P; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < M; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_parallel_columns(double A[N][M], double B[M][P], double C[N][P])
{
    int i, j, k;
    omp_set_num_threads(NUM_THREAD);
#pragma omp parallel for private(i, j, k) shared(A, B, C) schedule(static, BLOCK_SIZE)
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < P; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < M; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    double A[N][M];
    double B[M][P];
    double C[N][P];
    int i, j;

    // Initialize matrices A and B
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            A[i][j] = i + j;
        }
    }

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < P; j++)
        {
            B[i][j] = i - j;
        }
    }

    // 串行矩阵乘法
    double start_serial = omp_get_wtime();
    matrix_multiply_serial(A, B, C);
    double end_serial = omp_get_wtime();
    double serial_time = end_serial - start_serial;
    printf("串行乘法时间：%.6f s\n", serial_time);

    // 并行矩阵乘法（按行块划分）
    double start_parallel_rows = omp_get_wtime();
    matrix_multiply_parallel_rows(A, B, C);
    double end_parallel_rows = omp_get_wtime();
    double parallel_rows_time = end_parallel_rows - start_parallel_rows;
    printf("并行乘法时间（按行块划分）：%.6f s\n", parallel_rows_time);
    printf("加速比（按行块划分）：%.6f\n", serial_time / parallel_rows_time);
    printf("并行效率（按行块划分）：%.6f\n", serial_time / (parallel_rows_time * NUM_THREAD));

    // 并行矩阵乘法（按列块划分）
    double start_parallel_columns = omp_get_wtime();
    matrix_multiply_parallel_columns(A, B, C);
    double end_parallel_columns = omp_get_wtime();
    double parallel_columns_time = end_parallel_columns - start_parallel_columns;
    printf("并行乘法时间（按列块划分）：%.6f s\n", parallel_columns_time);
    printf("加速比（按列块划分）：%.6f\n", serial_time / parallel_columns_time);
    printf("并行效率（按列块划分）：%.6f\n", serial_time / (parallel_columns_time * NUM_THREAD));

    return 0;
}
