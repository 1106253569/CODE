#include <iostream>
#define maxsize 100
typedef int QElemType;
struct Sq_queue
{
    QElemType *base;
    int front;
    int rear;
};

void Init_queue(Sq_queue &Q)
{
    Q.base = new QElemType[maxsize];
}

int Queue_length(Sq_queue Q)
{
    return ((Q.rear - Q.front + maxsize) % maxsize);
}

void En_queue(Sq_queue &Q,QElemType e)
{
    if((Q.rear+1)%maxsize==Q.front)
        std::cout << " queue is full"
                  << "\n";
                  else
                  {
                      Q.base[Q.rear] = e;
                      Q.rear = (Q.rear + 1) % maxsize;
                  }
}

void De_queue(Sq_queue &Q,QElemType &e)
{
    if(Q.front==Q.rear)
        std::cout << "queue is empty"
                  << "\n";
                  else
                  {
                      e = Q.base[Q.front];
                      Q.front = (Q.front + 1) % maxsize;
                  }
}

