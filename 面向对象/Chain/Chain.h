#pragma once
#ifndef CHAIN
#include <iostream>
template <typename T>
class Linear_list
{
public:
    virtual ~Linear_list() {}
    //判断是否为空
    virtual bool empty() const = 0;
    //返回元素个数
    virtual int size() const = 0;
    //返回索引theIndex的元素
    virtual T& get(int theIndex) const = 0;
    //返回元素theElement第一次出现时的索引
    virtual int index_Of(const T& theElement) const = 0;
    //删除索引theIndex的元素
    virtual void erase(int theIndex) = 0;
    //把theElement插入到索引为theIndex的位置
    virtual void insert(int theIndex, const T& theElement) = 0;
    //把线性表插入输出流out
    virtual void output(std::ostream& os) const = 0;
};

template<typename T>
struct Chain_node
{
    T element;
    Chain_node<T>* next;

    //方法
    Chain_node() {}
    Chain_node(const T& element) { this->element = element; }
    Chain_node(const T& element, Chain_node<T>* next)
    {
        this->element = element;
        this->next = next;
    }
};

template<typename T>
class Chain :public Linear_list<T>
{
public:
    Chain(int initial_capacity = 10);
    Chain(const Chain<T>&);
    ~Chain;

    //方法
    bool empty() const { return list_size == 0; }
    int size()const { return list_size; }
    T& get(int) const;
    int index_Of(const T&) const;
    void erase(int);
    void insert(int, const T&);
    void output(std::ostream& os);

protected:
    void check_Index(int)const;
    Chain_node<T>* first_node;
    int list_size;
};

#endif // !CHAIN
