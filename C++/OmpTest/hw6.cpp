#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 100
#define THREAD_NUM 4

void oddEvenSortSerial(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = i % 2; j < size - 1; j += 2)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void oddEvenSortParallel(int arr[], int size)
{
    int phase, i, temp;
    for (phase = 0; phase < size; phase++)
    {
        if (phase % 2 == 0)
        {
#pragma omp parallel for 
            for (i = 1; i < size; i += 2*BLOCK_SIZE)
            {
                if (arr[i - 1] > arr[i])
                {
                    temp = arr[i - 1];
                    arr[i - 1] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        else
        {
#pragma omp parallel for
            for (i = 1; i < size - 1; i += 2*BLOCK_SIZE)
            {
                if (arr[i] > arr[i + 1])
                {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }
    }
}

int main()
{
    int size = 1e5;
    int arr[size];
    int i;

    // 生成随机数种子
    srand(time(NULL));

    // 生成随机数填充数组
    for (i = 0; i < size; i++)
    {
        arr[i] = rand();
    }

    double start, end;

    // 串行排序
    start = omp_get_wtime();
    oddEvenSortSerial(arr, size);
    end = omp_get_wtime();
    double serial_time = end - start;

    printf("串行排序时间：%fs\n", serial_time);

    // 并行排序
    omp_set_num_threads(THREAD_NUM);
    start = omp_get_wtime();
    oddEvenSortParallel(arr, size);
    end = omp_get_wtime();
    double parallel_time = end - start;

    printf("并行排序时间：%fs\n", parallel_time);
    printf("加速比：%f\n", serial_time / parallel_time);
    printf("并行效率：%f\n", serial_time / (parallel_time * THREAD_NUM));

    return 0;
}
