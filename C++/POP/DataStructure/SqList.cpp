#include <iostream>

#define MaxSize 50
typedef int ElmeType;

struct SqList
{
    ElmeType data[MaxSize];
    int length = 0;
    void Print();
} L;

void SqList::Print()
{
    for (int i = 0; i < length; i++)
        std::cout << data[i] << ' ';
    std::cout << '\n';
}

bool ListInsert(SqList &L, int i, ElmeType e)
{
    if (i < 0 || i > L.length)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j > i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElmeType &e)
{
    if (i < 0 || i >= L.length)
        return false;
    e = L.data[i];
    for (int j = i; j < L.length; j++)
        L.data[j] = L.data[j + 1];
    --L.length;
    return true;
}

int LocateElem(const SqList &L, ElmeType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i;
    return -1;
}

int main()
{
    ElmeType e;
    for (int i = 0; i < MaxSize / 2; i++)
    {
        L.data[i] = i;
        L.length++;
    }
    L.Print();
    ListDelete(L, 10, e);
    std::cout << e << ' ' << L.length << '\n';
    L.Print();
    ListInsert(L, 10, 30);
    L.Print();
    return 0;
}
