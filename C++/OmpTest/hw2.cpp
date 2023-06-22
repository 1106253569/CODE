#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define M 1000
#define N 1000
#define P 1000
#define BLOCK_SIZE 100

void matrix_multiply_parallel_rows_block(double *A, double *B, double *C, int m, int n, int p)
{
    omp_set_num_threads(8);
#pragma omp parallel for collapse(2)
    for (int i = 0; i < m; i += BLOCK_SIZE)
    {
        for (int j = 0; j < p; j++)
        {
            C[i * p + j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i * p + j] += A[i * n + k] * B[k * p + j];
            }
        }
    }
}

void matrix_multiply_parallel_row_rolling(double *A, double *B, double *C, int m, int n, int p)
{
    omp_set_num_threads(8);
#pragma omp parallel for collapse(2)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i * p + j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i * p + j] += A[i * n + k] * B[k * p + j];
            }
        }
    }
}

void matrix_multiply_parallel_columns_block(double *A, double *B, double *C, int m, int n, int p)
{
    omp_set_num_threads(8);
#pragma omp parallel for collapse(2)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j += BLOCK_SIZE)
        {
            C[i * p + j] = 0;
            for (int k = 0; k < n; k += BLOCK_SIZE)
            {
                for (int b = 0; b < BLOCK_SIZE; b++)
                {
                    for (int c = 0; c < BLOCK_SIZE; c++)
                    {
                        C[i * p + j + b] += A[i * n + k + b] * B[k * p + j + c];
                    }
                }
            }
        }
    }
}

int main()
{
    int i, j, k;
    double *A;
    double *B;
    double *C;

    // Initialize the matrices
    A = (double *)malloc(M * N * sizeof(double));
    B = (double *)malloc(N * P * sizeof(double));
    C = (double *)malloc(M * P * sizeof(double));
    for (i = 0; i < M * N; i++)
    {
        A[i] = i;
    }
    for (i = 0; i < N * P; i++)
    {
        B[i] = i;
    }

    double start_time, end_time;
    start_time = omp_get_wtime();
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < P; j++)
        {
            for (k = 0; k < N; k++)
            {
                C[i * P + j] += A[i * N + k] * B[k * P + j];
            }
        }
    }
    end_time = omp_get_wtime();
    double simple_time = end_time - start_time;
    printf("串行时间: %lfs\n", end_time - start_time);


    printf("并行计算\n");
    start_time = omp_get_wtime();
    matrix_multiply_parallel_rows_block(A, B, C, M, N, P);
    end_time = omp_get_wtime();
    printf("按行块计算时间: %lfs\n", end_time - start_time);
    printf("加速比: %f\n", simple_time / (end_time - start_time));

    start_time = omp_get_wtime();
    matrix_multiply_parallel_row_rolling(A, B, C, M, N, P);
    end_time = omp_get_wtime();
    printf("按行帘计算时间: %lfs\n", end_time - start_time);
    printf("加速比: %f\n", simple_time / (end_time - start_time));

    start_time = omp_get_wtime();
    matrix_multiply_parallel_columns_block(A, B, C, M, N, P);
    end_time = omp_get_wtime();
    printf("按列块计算时间: %lfs\n", end_time - start_time);
    printf("加速比: %f\n", simple_time / (end_time - start_time));

    return 0;
}
