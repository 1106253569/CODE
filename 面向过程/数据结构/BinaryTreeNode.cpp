#include <iostream>
template<typename T>
struct Binary_tree_Node
{
    T element;
    Binary_tree_Node<T> *left_Child, *right_child;
    Binary_tree_Node() { left_Child = right_child = NULL; }
    Binary_tree_Node(const T &theElement)
    {
        element(theElement)
            left_Child = right_child = NUll;
    }
    Binary_tree_Node(const T &theElement, Binary_tree_Node *the_Left_child, Binary_tree_Node *the_Right_child)
    {
        element(theElement)
            left_Child = the_Left_child,
            right_child = the_Right_child;
    }
};


//前序遍历二叉树
template <typename T>
void preOrder(Binary_tree_Node<T> *t)
{
    if(t!=NULL)
    {
        visit(t);
        pre_order(t->left_Child);
        pre_order(t->right_child);
    }
}

//中序遍历二叉树
template<typename T>
void inOrder(Binary_tree_Node<T> *t)
{
    if(t!=NULL)
    {
        post_Order(t->left_Child);
        post_Order(t->right_child);
        visit(t);
    }
}

//后序遍历二叉树
template<typename T>
void postOrder(Binary_tree_Node<T> *t)
{
    if(t!=NULL)
    {
        postOrder(t->left_Child);
        postOrder(t->right_child);
        visit(t);
    }
}

template<typename T>
void visit(Binary_tree_Node<T> *x)
{
    std::cout << x->element << ' ';
}

//输出中缀表达式
template<typename T>
void inFix(Binary_tree_Node<T> *t)
{
    if(t!=NULL)
    {
        std::cout << '(';
        inFix(t->left_Child);
        std::cout << t->element;
        inFix(t->right_child);
        std::cout << ')';
    }
}

//层次遍历二叉树
template<typename T>
void levelOrder(Binary_tree_Node<T> *t)
{
    Array_queue<Binary_tree_Node<T> *> q;
    while(t!=NULL)
    {
        visit(t);
        //将t的孩子插入队列
        if(t->left_Child!=NULL)
            q.push(t->left_Child);
        if(t->right_child!=NULL)
            q.push(t->right_child);
        //提取下一个要访问的节点
        try{
            t = q.front();
        }
        catch(queueEmpty){
            return;
        }
        q.pop();
    }
}