#include <iostream>
#include <string>
class TreeNode
{
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode() : value(""), count(1), left(nullptr), right(nullptr){}
    TreeNode(const std::string &s = std::string(), TreeNode *lchild = nullptr, TreeNode *Rchild = nullptr) : 
    value(s), count(1), left(lchild), right(Rchild){}
    TreeNode::TreeNode(const std::string &s = std::string());
    ~TreeNode();
};
class BinStrTree
{
private:
    TreeNode *root;
public:
    BinStrTree() : root(nullptr){}
};

TreeNode::TreeNode(const std::string&s=std::string())
{
    count++;
    value = s;
    left = right = nullptr;
}

TreeNode::~TreeNode()
{
}
