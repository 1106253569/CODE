#include <iostream>
#include <memory>
#include <vector>
#include <list>
template <typename>
class BlobPtr;
template <typename>
class Blob;
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template<typename T>
class Blob
{
    friend std::vector<T> &operator*(const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename It>
    Blob(It b, It e);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(const T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T &back();
    T &operator[](size_type i);
    

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template<typename T>
template<typename It>
Blob<T>::Blob(It b,It e):data(std::make_shared<std::vector>>(b,e)){}

template<typename T>
Blob<T>::Blob():
    data(std::make_shared<std::vector<T>>()){}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il):
    data(std::make_shared<std::vector<T>(il)){}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if(i>=data->size())
        throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
std::vector<T>& operator*(const Blob<T>&)
{
    return *data;
}

template<typename T>class BlobPtr
{
public:
    BlobPtr():curr(0){ }
    BlobPtr(Blob<T> &a,size_t sz=0):
            wptr(a.date),curr(sz){ }
    T& operator*(const Blob<T>&) const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr &operator++();
    BlobPtr &operator--();
private:
    std::shared_ptr<std::vector<T>>
    check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}
extern template class Blob<std::string>;
int main()
{
    
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<const char *> w = {"now", "is", "the", "time"};
    Blob<int> a2(vi.begin(), vi.end());
    Blob<std::string> a3(w.begin(), w.end());
}
