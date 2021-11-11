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
    //�ж��Ƿ�Ϊ��
    virtual bool empty() const = 0;
    //����Ԫ�ظ���
    virtual int size() const = 0;
    //��������theIndex��Ԫ��
    virtual T &get(int theIndex) const = 0;
    //����Ԫ��theElement��һ�γ���ʱ������
    virtual int index_Of(const T &theElement) const = 0;
    //ɾ������theIndex��Ԫ��
    virtual void erase(int theIndex) = 0;
    //��theElement���뵽����ΪtheIndex��λ��
    virtual void insert(int theIndex, const T &theElement) = 0;
    //�����Ա���������out
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

    //���캯��
    iterator(T *the_position = 0) { position = the_position; }

    //�����ò�����
    T &operator*() const { return *position; }
    T *operator->() const { return &*position; }

    //������ֵ����
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

    //��������ֵ����
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

    //�����Ƿ����
    bool operator!=(const iterator right) const { return position != right.position; }
    bool operator==(const iterator right) const { return position == right.position; }

protected:
    //ָ���Ԫ�ص�ָ��
    T *position;
};
