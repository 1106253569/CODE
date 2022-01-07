#include "Binary_tree.h"

//前序遍历
template <typename E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t)
{
    if (t != NULL)
    {
        linkedBinaryTree<E>::visit(t);
        preOrder(t->left_Child);
        preOrder(t->right_child);
    }
}

template <typename E>
int  linkedBinaryTree<E>::height(binaryTreeNode<E> *t)
{
    if (t == NULL)
        return 0;
    int hl = height(t->left_Child);
    int hr = height(t->right_child);
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}