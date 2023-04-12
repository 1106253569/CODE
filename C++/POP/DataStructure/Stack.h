#include <iostream>
#define MaxSize 50
typedef int Elemtype;

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
