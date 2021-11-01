#include <iostream>
#include <type_traits>
template<typename T>
class Foo
{
public:
    static std::size_t count() { return ctr; }
private:
    static std::size_t ctr;
};

template <typename T>
size_t Foo<T>::ctr = 0;

template<typename T>
typename T::value_type top(const T& c)
{
    if(!c.empty())
        return c.back(); 
        else
            return typename T::value_type();
}

template<typename T,typename F=std::less<T>>
int compare(const T&v1,const T&v2,F f=F())
{
    if(f(v1,v2))
        return -1;
        else if(f(v2,v1))
            return 1;
        return 0;
}

template <typename T>
T fobj(T, T);

template <typename T>
T fref(const T &, const T &);

template <typename T>
std::ostream& print(std::ostream& os,const T &obj)
{
    return os << obj;
}

template <typename T1, typename T2, typename T3>
T1 sum(T2 &, T3 &);

template <typename T>
auto fcn(T beg,T end)->decltype(*beg)
{
    return *beg;
}

template<typename T>
void f3(T&& val)
{
    T t = val;
    t = fcn(t);
    if(val==t)
    {

    }
}

template<typename T>
typename std::remove_reference<T>::type&& move(T&& t)
{
    return std::static_cast<typename std::remove_reference<T>::type &&>(t);
}

template<typename F,typename T1,typename T2>
void flip1(F f,T1 t1,T2 t2)
{
    f(t2, t1);
}
void f(int v1,int v2)
{
    std::cout << v1 << " " << ++v2 << "\n";
}

template<typename Type>
Type intermediary(Type&& arg)
{
    finalFcn(std::forward<Type>(arg));
}

int main()
{
    Foo<int> fi;
    auto ct = Foo<int>::count();
    ct = fi.count();
    std::cout << ct;
    return 0;
}