#include <iostream>
using Link_list=struct information
{
    int order;
    std::string name;
    Link_list * next;
};

inline void Creates(Link_list* &L)//创建头节点
{
    Link_list* p =new Link_list;
    L->next = p;
    p->next=NULL;
}

int count_lenght(Link_list* &L)//计算长度
{
    Link_list* p;
    p=L;
    int i=0;
    while(p->next==NULL)
    {
        p=p->next;
        ++i;
    }
    return i;
}

Link_list* search(Link_list*&L,std::string &student) //姓名查询
{
    Link_list*p=L->next;
    while (p->next==NULL)
    {
        if(p->name==student)
        {
            return p;
        }
        p=p->next;
    }
    std::cout<<"查无此人"<<"\n";
    return p;
}

Link_list* search(Link_list*&L,int ord)//学号查询
{
    Link_list*p=L->next;
    while (p->next==NULL)
    {
        if(p->order==ord)
        {
            return p;
        }
        p=p->next;
    }
    std::cout<<"查无此人"<<"\n";
    return p;
}

void add(Link_list*&L)//添加元素
{
    Link_list* p;
    p = L->next;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    std::cin >> p->order >> p->name;
}

void MergeList_L(Link_list *&La,Link_list* &Lb,Link_list* &Lc)//合并链表
{
    Link_list* pa = La->next;
    Link_list *pb = Lb->next;
    Lc = La;
    Link_list *pc = Lc;
    while (pa&&pb)
    {
        if(pa->order<=pb->order)
        {
            pc->next = pa;
            pc = pa;
            pb = pb->next;
        }
        else
        {
            pc->next = pa;
            pc = pb;
            pb = pb->next;
        }
        pc->next = pa ? pa : pb;
        delete Lb;
    }
    
}