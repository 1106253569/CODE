#include "base.h"

struct SqQueue
{
    ElemType data[MaxSize];
    int front, rear;
    bool rag;
    void Print()
    {
        for (int i = front; i < rear; i++)
            std::cout << data[i] << ' ';
        std::cout << '\n';
    }
};

struct LinkNode
{
    ElemType data;
    LinkNode *next;
};

struct LinkQueue
{
    LinkNode *front, *rear;
};
