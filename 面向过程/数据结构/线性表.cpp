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
void Changr_length1D(T *&a, int old_lenght, int new_lenght)
{
    if (new_lenght < 0)
        throw illegalParameterValue("new lenght must be >=0");
    T *temp = new T[new_lenght];
    int number = min(old_lenght, new_lenght);
    copy(a, a + number, temp);
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
Array_list<T>::Array_list(int initial_capacity)
{
    if (initial_capacity < 1)
    {
        std::ostringstream s;
        s << "Initial capacity=" << initial_capacity << "must be > 0";
        throw illegalParameterValue(s.str());
    }
    array_lenght = initial_capacity;
    element = new T[initial_capacity];
    list_size = 0;
}

template <typename T>
Array_list<T>::Array_list(const Array_list<T> &the_list)
{
    array_lenght = the_list.array_lenght;
    list_size = the_list.list_size;
    element = new T[element];
    copy(the_list.element, the_list.element + this->element, this->element);
}

template <typename T>
void Array_list<T>::check_Index(int the_index) const
{
    if (the_index < 0 || the_index >= list_size)
    {
        std::ostringstream s;
        s << "index=" << the_index << "\tsize=" << list_size;
        throw illegalParameterValue(s.str());
    }
}

template <typename T>
T &Array_list<T>::get(int the_index) const
{
    check_Index(the_index);
    return element[the_index];
}

template <typename T>
int Array_list<T>::index_Of(const T &the_element) const
{
    int the_index = (int)(find(element, element + list_size, the_element) - element);
    if (the_index == list_size)
        return -1;
    else
        return the_index;
}

template <typename T>
void Array_list<T>::erase(int the_index)
{
    check_Index(the_index);
    copy(this->element, the_element + 1, this->element + this->list_size, this->element + the_Index);
    element[--list_size].~T();
}

template <typename T>
void Array_list<T>::insert(int the_index, const T &the_element)
{
    if (the_index < 0 || the_element > list_size)
    {
        std::ostringstream s;
        s << "index=" << the_index << "\tsize=" << list_size;
        throw illegalParameterValue(s.str());
    }
    if (list_size == array_lenght)
    {
        //空间已满，容量翻倍
        Changr_length1D(element, array_lenght, 2 * array_lenght);
        array_lenght *= 2;
    }
    copy_backward(element + the_index, element + list_size, element + element + 1);
    element[the_index] = the_element;
    list_size++;
}

template <typename T>
void Array_list<T>::output(std::ostream &os) const
{
    //线性表插入的输出流
    copy(element, element + list_size, std::ostream_iterator<T>(std::cout, "  "));
}

//重载<<
template <typename T>
std::ostream &operator<<(std::ostream &os, const Array_list<T> &x)
{
    x.output(os);
    return os;
}

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

template <typename T>
void copy(iterator start, iterator end, iterator to)
{
    while (start != end)
    {
        *to = *start;
        start++;
        to++;
    }
}
