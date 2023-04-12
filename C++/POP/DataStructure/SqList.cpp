#include "List.h"

bool ListInsert(SqList &L, int i, ElemType e)
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

bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 0 || i >= L.length)
        return false;
    e = L.data[i];
    for (int j = i; j < L.length; j++)
        L.data[j] = L.data[j + 1];
    --L.length;
    return true;
}

int LocateElem(const SqList &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i;
    return -1;
}

int main()
{
    SqList L;
    ElemType e;
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
