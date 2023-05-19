#include "List.h"

void List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
}

void LLPrint(LinkList L)
{
    LNode *temp = L->next;
    while (temp != NULL)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

int main()
{
    LinkList L;
    List_HeadInsert(L);
    LLPrint(L);
    return 0;
}