#pragma once
#ifndef BINARYTREE
#define BINARYTREE
#include <iostream>
template <typename T>
class binaryTree
{
public:
    virtual ~binaryTree() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void preOrder(void (*)(T *)) = 0;
    virtual void inOrder(void (*)(T *)) = 0;
    virtual void postOrder(void (*)(T *)) = 0;
    virtual void levelOrder(void (*)(T *)) = 0;
};

template <typename T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *left_Child, *right_child;
    binaryTreeNode() { left_Child = right_child = NULL; }
    binaryTreeNode(const T &theElement)
    {
        element(theElement)
            left_Child = right_child = NULL;
    }
    binaryTreeNode(const T &theElement, binaryTreeNode *the_Left_child, binaryTreeNode *the_Right_child)
    {
        element(theElement)
            left_Child = the_Left_child,
            right_child = the_Right_child;
    }
};

template <typename E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>>
{
public:
    linkedBinaryTree()
    {
        root = NULL;
        treeSize = 0;
    }
    ~linkedBinaryTree() { erase(); }
    bool empty() const { return treeSize == 0; }
    int size() const { return treeSize; }
    void preOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        preOrder(root);
    }
    void inOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        inOrder(root);
    }
    void postOrder(void (*theVisit)(binaryTreeNode<E> *))
    {
        visit = theVisit;
        postOrder(root);
    }
    void levelOrder(void (*)(T *));
    void erase()
    {
        postOrder(dispose);
        root = NULL;
        treeSize = 0;
    }
    int height() const { return height(root); }

private:
    //指向根的指针
    binaryTreeNode<E> *root;
    //树的节点个数
    static void (*visit)(binaryTreeNode<E> *);
    //访问函数
    static void preOrder(binaryTreeNode<E> *t);
    static void inOrder(binaryTreeNode<E> *t);
    static void postOrder(binaryTreeNode<E> *t);
    static void dispose(binaryTreeNode<E> *) { delete t; }
    int height(binaryTreeNode<E> *t);
};

#endif