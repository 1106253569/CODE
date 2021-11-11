#pragma once
#include <iostream>
template <typename T>
class illegalParameterValue
{
private:
    std::string message;

public:
    illegalParameterValue() : message("Illegal parameter value") {}
    illegalParameterValue(char *theMassage) { message = std::string(theMassage); }
    void outputMessage() { std::cout << message << "\n"; }
    ~illegalParameterValue() = default;
};

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
    virtual T &get(int theIndex) const = 0;
    //返回元素theElement第一次出现时的索引
    virtual int index_Of(const T &theElement) const = 0;
    //删除索引theIndex的元素
    virtual void erase(int theIndex) = 0;
    //把theElement插入到索引为theIndex的位置
    virtual void insert(int theIndex, const T &theElement) = 0;
    //把线性表插入输出流out
    virtual void output(std::ostream &os) const = 0;
};

template <typename T>
void changeLength2D(T **&a, int oldRows, int copyRows,
                    int copyColumns, int newRows, int newColumns)
{
    // Resize the two-dimensional array a that has oldRows number of rows.
    // The dimensions of the resized array are newRows x newColumns.
    // Copy the top left oldRows x newColumns sub array into the resized array.
    // make sure new dimensions are adequate
    if (copyRows > newRows || copyColumns > newColumns)
        throw illegalParameterValue("new dimensions are too small");

    T **temp = new T *[newRows]; // array for rows
    // create row arrays for temp
    for (int i = 0; i < newRows; i++)
        temp[i] = new T[newColumns];
    // copy from old space to new space, delete old space
    for (int i = 0; i < copyRows; i++)
    {
        copy(a[i], a[i] + copyColumns, temp[i]);
        delete[] a[i]; // deallocate old memory
    }

    // delete remaining rows of a
    for (int i = copyRows; i < oldRows; i++)
        delete[] a[i];
    delete[] a;
    a = temp;
}

template <typename T>
class Array_list : public Linear_list<T>
{
public:
    Array_list(int initial_capacity = 10);
    Array_list(const Array_list<T> &);
    ~Array_list() { delete[] element; }
    //by inherit
    bool empty() const { return list_size == 0; }
    int size() const { return list_size; }
    T &get(int the_index) const;
    int index_Of(const T &the_element) const;
    void erase(int the_index);
    void insert(int the_index, const T &the_element);
    void output(std::ostream &os) const;
    //other
    int capacity() const { return array_lenght; }

protected:
    void check_Index(int) const;
    T *element;
    int list_size;
    int array_lenght;
};

template <typename T>
class iterator
{
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = *T;
    using reference = T &;

    //构造函数
    iterator(T *the_position = 0) { position = the_position; }

    //解引用操作符
    T &operator*() const { return *position; }
    T *operator->() const { return &*position; }

    //迭代器值增加
    iterator &operator++()
    {
        ++position;
        return *this;
    }
    iterator operator++(int)
    {
        iterator old = *this;
        ++position;
        return old;
    }

    //迭代器的值减少
    iterator &operator--()
    {
        --position;
        return *this;
    }
    iterator operator--(int)
    {
        iterator old = *this;
        --position;
        return *this;
    }

    //测试是否相等
    bool operator!=(const iterator right) const { return position != right.position; }
    bool operator==(const iterator right) const { return position == right.position; }

protected:
    //指向表元素的指针
    T *position;
};
