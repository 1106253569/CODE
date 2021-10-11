#include <iostream>
using namespace std;
struct listnode 
{
    int data;
    listnode *next;
};
int main()
{
    listnode *input();
    listnode *deletem( listnode *L, int m );
    listnode *head;
    head = input();
    int m;
    cin >> m;
    deletem(head, m);
    void *print(listnode * x);
    print(head);
}

listnode*input()
{
    listnode *head, *p1, *p2;
    int n = 0;
    p1 = p2 = new listnode;
    head = NULL;
    cin >> p1->data;
    while(p1->data!=-1)
    {
        if(n==0)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = new listnode;
        cin >> p1->data;
        n++;
    }
    p2->next = NULL;
    return (head);
}

void *print(listnode * x)
{
    listnode *p1;
    p1 = x;
    while(p1->next!=0)
    {
        cout << p1->data << " ";
        p1 = p1->next;
    }
}

listnode *deletem( listnode *L, int m )
{
    int number(listnode * x);
    listnode *p1, *p2;
    p1 = p2 = L;
    int n = 0;
    while(p2->next!=NULL)
    {
        n += 1;
        p2 = p1;
        p1 = p1->next;
        if(n==number(L))
            {
                if(p2->data==m)
                {
                    p2 = NULL;
                    return(L);
                }       
            }
        if(p1->data==m)
        {
            if (n == 1)
                L->next = p1->next;
            else
                p2->next = p1->next;
        }
        
    }
    return (L);
}

int number(listnode *x)
{
    int n = 0;
    listnode *p ;
    p = x;
    while(p->next!=NULL)
        {
            n++;
            p = p->next;
        }
    return (n);
}

