#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ROWS 1000000
#define COLS 1000000
#define NNZ 10000000
#define NUM_THREADS 8
#define ELEMENTS_PER_BLOCK 1000

typedef struct
{
    int rows;      // 矩阵行数
    int *row_off;  // 行偏移数组
    int *cols;     // 列索引数组
    double *data;  // 非零元素值数组
    int data_size; // 非零元素个数
} CsrMatrix;

typedef struct
{
    int start; // 块的起始行索引
    int end;   // 块的结束行索引
} CsrBlock;

void csr_spmv(const CsrMatrix &csr_matrix, double *vec, double *result)
{
    for (int i = 0; i < csr_matrix.rows; i++)
    {
        int start = csr_matrix.row_off[i];
        int num = csr_matrix.row_off[i + 1] - csr_matrix.row_off[i];
        double temp = 0;
        for (int j = 0; j < num; j++)
        {
            temp += vec[csr_matrix.cols[start + j]] * csr_matrix.data[start + j];
        }
        result[i] = temp;
    }
}

void csr_spmv_parallel_unoptimized(const CsrMatrix &csr_matrix, double *vec, double *result)
{
#pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < csr_matrix.rows; i++)
    {
        int start = csr_matrix.row_off[i];
        int num = csr_matrix.row_off[i + 1] - csr_matrix.row_off[i];
        double temp = 0;
        for (int j = 0; j < num; j++)
        {
            temp += vec[csr_matrix.cols[start + j]] * csr_matrix.data[start + j];
        }
        result[i] = temp;
    }
}

void spmv(const CsrMatrix *matrix, const double *x, double *y, const CsrBlock *block)
{
#pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = block->start; i < block->end; i++)
    {
        double sum = 0.0;
        int start = matrix->row_off[i];
        int end = matrix->row_off[i + 1];
        for (int j = start; j < end; j++)
        {
            int col = matrix->cols[j];
            double value = matrix->data[j];
            sum += value * x[col];
        }
        y[i] = sum;
    }
}

void spmv_parallel(const CsrMatrix *matrix, const double *x, double *y)
{
    int num_blocks = (matrix->rows + ELEMENTS_PER_BLOCK - 1) / ELEMENTS_PER_BLOCK;
    int rows_per_block = matrix->rows / num_blocks;
    int remaining_rows = matrix->rows % num_blocks;

#pragma omp parallel num_threads(NUM_THREADS)
    {
        int tid = omp_get_thread_num();
        int start_row = tid * rows_per_block;
        int end_row = start_row + rows_per_block;
        if (tid == NUM_THREADS - 1)
        {
            end_row += remaining_rows;
        }
        CsrBlock block;
        block.start = start_row;
        block.end = end_row;
        spmv(matrix, x, y, &block);
    }
}

int main()
{
    // 创建稀疏矩阵并初始化...

    CsrMatrix matrix;
    matrix.rows = ROWS;
    matrix.row_off = (int *)malloc((ROWS + 1) * sizeof(int));
    matrix.cols = (int *)malloc(NNZ * sizeof(int));
    matrix.data = (double *)malloc(NNZ * sizeof(double));
    matrix.data_size = NNZ;

    // 生成不均匀分布的稀疏矩阵数据...

    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        matrix.row_off[i] = i * (NNZ / ROWS);
    }
    matrix.row_off[ROWS] = NNZ;
    for (i = 0; i < NNZ; i++)
    {
        matrix.cols[i] = rand() % COLS;             // 随机列索引
        matrix.data[i] = (double)rand() / RAND_MAX; // 随机值范围：[0, 1]
    }

    // 随机生成向量x...

    double *x = (double *)malloc(COLS * sizeof(double));
    for (i = 0; i < COLS; i++)
    {
        x[i] = (double)rand() / RAND_MAX; // 随机值范围：[0, 1]
    }

    // 分配结果向量y...

    double *y = (double *)malloc(ROWS * sizeof(double));
    double *y_serial = (double *)malloc(ROWS * sizeof(double));

    // 执行串行SPMV算法并计算运行时间...

    double start_time = omp_get_wtime();
    csr_spmv(matrix, x, y_serial);
    double serial_execution_time = omp_get_wtime() - start_time;
    printf("串行SPMV执行时间: %.6f秒\n", serial_execution_time);

    // 执行并行SPMV算法（未优化）并计算运行时间
    start_time = omp_get_wtime();
    csr_spmv_parallel_unoptimized(matrix, x, y);
    double unoptimized_parallel_execution_time = omp_get_wtime() - start_time;
    printf("未优化并行SPMV执行时间: %.6f秒\n", unoptimized_parallel_execution_time);

    // 执行并行SPMV算法（优化后）并计算运行时间
    start_time = omp_get_wtime();
    spmv_parallel(&matrix, x, y);
    double optimized_parallel_execution_time = omp_get_wtime() - start_time;
    printf("优化后并行SPMV执行时间: %.6f秒\n", optimized_parallel_execution_time);
    printf("优化前后并行SPMV加速比: %.2f\n", unoptimized_parallel_execution_time / optimized_parallel_execution_time);

    // 结果验证
    int is_equal = 1;
    for (int i = 0; i < ROWS; i++)
    {
        if (fabs(y[i] - y_serial[i]) > 1e-9)
        {
            is_equal = 0;
            break;
        }
    }
    printf("验证: %s\n", is_equal ? "结果相同" : "结果不同");

    // 释放内存...
    free(matrix.row_off);
    free(matrix.cols);
    free(matrix.data);
    free(y_serial);
    free(x);
    free(y);

    return 0;
}
