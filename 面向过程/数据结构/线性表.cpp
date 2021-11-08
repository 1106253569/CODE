#include <iostream>
template<typename T>
class Linear_list
{
public:
    virtual ~Linear_list() {}
    //判断是否为空
    virtual bool empty() const = 0;
    //返回元素个数
    virtual int size() const = 0;
    //返回索引theIndex的元素
    virtual T &get(int theIndex) const = 0;
    //返回元素theElement第一次出现时的索引
    virtual int indexOf(const T &theElement) const = 0;
    //删除索引theIndex的元素
    virtual void erase(int theIndex) = 0;
    //把theElement插入到索引为theIndex的位置
    virtual void insert(int theIndex, const T &theElement) = 0;
    //把线性表插入输出流out
    virtual void output(std::ostream &os) const = 0;
};