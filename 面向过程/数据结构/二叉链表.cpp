#include <iostream>
#define TElemType int
struct Binode
{
    TElemType date;
    Binode *Left_child;
    Binode *right_child;
};
using BiTree = Binode *;

void Preorder_Traverse(BiTree T)
{
    if(T!=NULL)
    {
        std::cout << T->date<<"\n";
        Preorder_Traverse(T->Left_child);
        Preorder_Traverse(T->right_child);
    }
}

void Inorder_Traverse(BiTree T)
{
    if(T!=NULL)
    {
        Inorder_Traverse(T->Left_child);
        std::cout << T->date<<"\n";
        Inorder_Traverse(T->right_child);
    }
}

void Postorder_Traverse(BiTree T)
{
    if(T!=NULL)
    {
        Inorder_Traverse(T->Left_child);
        Inorder_Traverse(T->right_child);
        std::cout << T->date<<"\n";
    }
}

int Cope(BiTree T,BiTree &NewT)
{
    if(T==NULL)
    {
        NewT = NULL;
        return 0;
    }
    else 
    {
        NewT = new Binode;
        NewT->date = T->date;
        Cope(T->Left_child, NewT->Left_child);
        Cope(T->right_child, NewT->right_child);
    }
}

int Deepth(BiTree T)
{
    if(T==NULL)
        return 0;
        else 
        {
            int m = Deepth(T->Left_child);
            int n = Deepth(T->right_child);
            if(m>n)
                return (m + 1);
                else
                    return (n + 1);
        }
}

int Node_couut(BiTree T)
{
    if(T==NULL)
        return 0;
        else
            return Node_couut(T->Left_child) + Node_couut(T->right_child) + 1;
}

int Leaf_count(BiTree T)
{
    if(T==NULL)
        return 0;
    if(T->Left_child==NULL&&T->right_child==NULL)
        return 1;
        else
            return Leaf_count(T->Left_child) + Leaf_count(T->right_child);
}

