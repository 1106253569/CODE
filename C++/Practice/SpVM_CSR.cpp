// 引入必要的头文件
#include <iostream>
#include <vector>

// 定义一个函数来计算CSR格式的稀疏矩阵和向量的乘积
void SpMV_CSR(int n, std::vector<int> &rowPtr,
              std::vector<int> &colIndex, std::vector<double> &value,
              std::vector<double> &x, std::vector<double> &y)
{
    // 输入参数：
    // n: 矩阵的行数
    // rowPtr: 矩阵的行偏移数组，长度为n+1
    // colIndex: 矩阵的列索引数组，长度为非零元素个数
    // value: 矩阵的非零元素值数组，长度为非零元素个数
    // x: 向量x，长度为n
    // 输出参数：
    // y: 结果向量y，长度为n

    // 遍历每一行
    for (int i = 0; i < n; i++)
    {
        // 初始化结果向量中当前行的值为0
        y[i] = 0;
        // 获取当前行的非零元素范围
        int start = rowPtr[i];
        int end = rowPtr[i + 1];
        // 遍历当前行的非零元素
        for (int j = start; j < end; j++)
        {
            // 获取非零元素的列索引和值
            int col = colIndex[j];
            double val = value[j];
            // 将非零元素与向量中对应的元素相乘，并累加到结果向量中
            y[i] += val * x[col];
        }
    }
}

// 定义一个函数来打印向量的内容
void print_vector(std::vector<double> &v)
{
    for (auto &x : v)
        std::cout << x << " ";
    std::cout << '\n';
}

// 定义一个函数来打印稀疏矩阵的内容
void print_matrix(int n, std::vector<int> &rowPtr, std::vector<int> &colIndex, std::vector<double> &value)
{
    // 输入参数：
    // n: 矩阵的行数
    // rowPtr: 矩阵的行偏移数组，长度为n+1
    // colIndex: 矩阵的列索引数组，长度为非零元素个数
    // value: 矩阵的非零元素值数组，长度为非零元素个数
    std::cout << "---------------\n";
    // 遍历每一行
    for (int i = 0; i < n; i++)
    {
        // 获取当前行的非零元素范围
        int start = rowPtr[i];
        int end = rowPtr[i + 1];
        // 定义一个指针指向当前行的第一个非零元素
        int p = start;
        // 遍历每一列
        for (int j = 0; j < n; j++)
        {
            // 如果当前列有非零元素，且列索引与j相等，则打印该元素的值，并将指针后移一位
            if (p < end && colIndex[p] == j)
            {
                std::cout << value[p] << " ";
                p++;
            }
            else
            {
                // 否则，打印0
                std::cout << "0 ";
            }
        }
        // 换行
        std::cout << std::endl;
    }
    std::cout << "---------------\n";
}

// 定义一个主函数来测试算法
int main()
{
    // 定义一个稀疏矩阵和一个向量，以及结果向量
    int n = 4;                                                                         // 矩阵的行数
    std::vector<int> rowPtr = {0, 2, 4, 7, 9};                                         // 行偏移数组
    std::vector<int> colIndex = {0, 1, 1, 2, 0, 2, 3, 1, 3};                           // 列索引数组
    std::vector<double> value = {1.0, -1.0, -3.0, -2.0, -4.0, -1.0, -5.0, -4.0, -6.0}; // 非零元素值数组
    std::vector<double> x = {1.0, -2.0, -3.0, -4.0};                                   // 向量x
    std::vector<double> y(n);                                                          // 结果向量y

    print_matrix(n, rowPtr, colIndex, value);

    // 调用SpMV_CSR函数计算结果向量y
    SpMV_CSR(n, rowPtr, colIndex, value, x, y);

    // 打印结果向量y
    print_vector(y);

    return 0;
}