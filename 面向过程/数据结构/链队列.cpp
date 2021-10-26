#include <iostream>
#define maxsize 100
typedef int QElemType;
struct Qnode
{
    QElemType date;
    Qnode *next;
};
using Queue_prt = Qnode *;
struct Link_queue
{
    Queue_prt front;
    Queue_prt rear;
};

void Init_queue(Link_queue &Q)
{
    Q.front = Q.rear=new Qnode;
    if(!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
}

void Destroy_queue(Link_queue &Q)
{
    while (Q.front)
    {
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }    
}

void En_queue(Link_queue &Q,QElemType e)
{
    Queue_prt p = new Qnode;
    if(!p)
        exit(OVERFLOW);
    p->date = e;
    p->next = NULL;
    Q.rear = p;
}

void De_queue(Link_queue &Q,QElemType e)
{
    if(Q.front==Q.rear)
        std::cout << "queue is empty"
                  << "\n";
                  else
                  {
                      Queue_prt p;
                      p = Q.front->next;
                      e = p->date;
                      Q.front->next=p->next;
                      if(Q.rear==p)
                          Q.rear = Q.front;
                      delete p;
                  }
}

void Get_head(Link_queue &Q,QElemType &e)
{
    if(Q.front==Q.rear)
        std::cout << "queue is empty"
                  << "\n";
                  else
                  {
                      e = Q.front->next->date;
                  }
}