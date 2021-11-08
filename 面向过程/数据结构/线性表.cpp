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
    void check_Index(int the_Index) const;
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
