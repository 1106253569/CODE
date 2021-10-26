#include <iostream>
#define maxsize 100
typedef int SElemType;
struct Sq_stack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
};

void initstack(Sq_stack &S)  //初始化
{
    S.base = new SElemType[maxsize];
    if(!S.base)
        exit(OVERFLOW); 
        /*exit是c++程序的退出函数，声明为void exit(int value)
        其功能是退出当前的程序，并将参数value返回主调进程
        OVERFLOW为math.h的一个宏定义，其值为3。
        含义为运算过程中出现了上溢，即运算结果超出了运算变量所能存储的范围。*/
    S.top = S.base;
    S.stacksize = maxsize;
}

int stacklength(Sq_stack& S) //求长
{
    return S.top - S.base;
}

void clearstack(Sq_stack& S) //清空栈
{
    if(S.base)
        S.top = S.base;
}

void destroystack(Sq_stack& S) //销毁栈
{
    if(S.base)
    {
        delete S.base;
        S.stacksize = 0;
        S.base = S.top = NULL;
    }
}

void push(Sq_stack& S,SElemType e) //进栈
{
    if(S.top-S.base==S.stacksize)
        std::cout << "栈满"
                  << "\n";
    else
        *S.top++ = e;
    /* *S.top=e;
       S.top++; */
}

void Pop(Sq_stack &S,SElemType &e) //出栈
{
    if(S.top==S.base)
        std::cout << "空栈"
                  << "\n";
    else
        e = *--S.top;
}
