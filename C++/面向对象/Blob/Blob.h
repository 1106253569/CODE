#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <list>
template <typename>
class BlobPtr;
template <typename>
class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob
{
    friend std::vector<T>& operator*(const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename It>
    Blob(It b, It e);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T& t) { data->push_back(t); }
    void push_back(const T&& t) { data->push_back(std::move(t)); }
    T& back();
    T& operator[](size_type i);
    

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string& msg) const;
};

template<typename T>
int compare(const T& v1, const T& v2)
{
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;
    return 0;
}

template<typename T, typename F = std::less<T>>
    int compare(const T& v1, const T& v2, F f = F())
    {
        if (f(v1, v2))
            return -1;
        if (f(v2, v1))
            return 1;
        return 0;
    }

