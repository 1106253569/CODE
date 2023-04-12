#include <iostream>

#define InitSize 100
typedef int ElmeType;

struct SeqList
{
    ElmeType *data;
    int MaxSize, length;
};

int main()
{
    SeqList L;
    L.data = (ElmeType *)malloc(sizeof(ElmeType) * InitSize);
}
