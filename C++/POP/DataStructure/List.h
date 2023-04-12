#include <iostream>

#define MaxSize 50
#define InitSize 100
typedef int ElemType;

//静态顺序表
struct SqList
{
	ElemType data[MaxSize];
	int length=0;
	void Print()
	{
		for (int i = 0; i < length; i++)
			std::cout << data[i] << ' ';
		std::cout << '\n';
	}
};

//动态顺序表
struct SeqList
{
	ElemType *data;
	int MaxSize1, length;
};

//链表
typedef struct LNode
{
	ElemType data;
	LNode *next;
} *LinkList;

