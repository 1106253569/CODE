#include <iostream>
#include <time.h>
#include <ctime>
// 归并排序
template <typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end)
{
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
template <typename T>
void merge_sort(T arr[], const int len)
{
    T *reg=new T[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

int main()
{
    int n;
    std::cout << "数组大小: ";
    std::cin >> n;
    int q[n];
    std::cout << "原数组顺序:" << '\n';
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
    {
        q[i] = rand() % 10000; // 随机50之间的数字来 初始化数组num_ary
        std::cout << q[i] << '\t';
    }
    std::cout << '\n';
    clock_t start=clock();		//程序开始计时
    merge_sort(q, n);
    clock_t end=clock();		//程序结束用时
    std::cout << "排序后:" << '\n';
    for (auto a : q)
        std::cout << a << "\t";
    std::cout << '\n';
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	std::cout<<"Total time:"<<endtime*1000<<"ms"<<'\n';		//ms为单位
    return 0;
}
