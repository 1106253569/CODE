#include "Metix.h"

//判断行列是否相等
void Metix::check() const
{
    if (this->Max_line() != this->Max_row())
        throw std::out_of_range("line!=row");
}

//矩阵倍数相乘
Metix& Metix::operator*(int n) const
{
    for (int i = 0; i < this->Max_line(); i++)
        for (auto& j : (*this)[i])
            j* n;
}

Metix::Metix(std::istream&is)
{
    printf("输入矩阵行数");
    int n;
    is >> n;
    printf("输入列数");
    int m;
    is>>m;
    printf("输入数值");
    int i = 0,x = 0;
    while ( i< n)
    {
        std::vector<double> line;
        while (line.size() <= m)
        {
            is >> x;
            line.push_back(x);
        }
        this->push_back(line);
        ++i;
    }
}

//判断同型矩阵
bool Metix::operator==(const Metix&M) const
{
    if (this->Max_line() == M.Max_line() && this->Max_row() == M.Max_row())
        return true;
    else
        return false;
}

//计算逆序数
int sort(const std::vector<double>& A) 
{
    int k = 0, b = 1;
    for (int i = 1; i < A.size(); i++)
        for (int j = 0; j < i; j++)
            if (A[i] < A[j])
                ++k;
    return (b*pow(-1,k));
}
//利用递归收集数据
double Data(const Metix& M,std::vector<double>& A,std::vector<int>& sub)
{
    int i=0;
    double sum=0.0;
    while(i<M.Max_line())
    {
        //lameda函数判断是否为完全不同的列数
        if([i,sub]()->bool
        {for(const auto j:sub)
            if(i==j)
                return false;
        return true;})
        {
            A.push_back(M[sub.size()][i]);
            sub.push_back(i);
            //已经加入各行元素则进行计算
            if(A.size()==M.Max_row())
            {
                for(auto i:A)
                sum+=i;
                return sort(sub)*sum;
            }
            //未加入完毕则继续递归
            else
                Data(M,A,sub);
        }
        else
            ++i;
    }
}
//计算矩阵行列式
double Metix::Dterminant()
{
    check();
    //存储数据
    std::vector<double> data;
    //存储下标位置
    std::vector<int> subscript;
    return Data(*this,data,subscript);
}