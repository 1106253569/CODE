#include <iostream>
#define maxsize 100
typedef int SElemType;
struct Link_stack
{
    SElemType date;
    Link_stack *next;
};

void init_stack(Link_stack* &S)  //初始化
{
    S = NULL;
}

void Stack_empty(Link_stack* &S) //判断空栈
{
    if(S==NULL)
        std::cout << "空栈"
                  << "\n";
                  else
                      std::cout << "非空栈"
                                << "\n";
}

void push(Link_stack* &S,SElemType e) //入栈
{
    Link_stack *p;
    p = new Link_stack;
    p->date = e;
    p->next = S;
    S = p;
}

void pop(Link_stack* &S,SElemType &e) //出栈
{
    if(S==NULL)
        std::cout << "ERROR"
                  << "\n";
                  else
                    {
                        Link_stack *p;
                        e = S->date;
                        p = S;
                        S = S->next;
                        delete p;
                    }
}

Link_stack* get_top(Link_stack* &S) //取栈顶元素
{
    Link_stack *p;
    if(S!=NULL)
        p = S;
    return p;
}


