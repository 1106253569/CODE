#include "base.h"

struct SqStack
{
    Elemtype data[MaxSize];
    int top;
};

typedef struct LinkNode
{
    Elemtype data;
    LinkNode *next;
} *LiStack;
