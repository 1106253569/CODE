#include <iostream>
struct HtNode
{
    int weight;
    int parent, Left_child, Right_chlid;
};
using Huffman_tree = HtNode *;

void Creat_HuffmanTree(Huffman_tree HT,int n)
{
    if(n>1)
    {
        int m = 2 * n - 1;
        HT = new HtNode[m + 1];
        for (int i = 1; i <= m;++i)
        {
            HT[i].Left_child = 0;
            HT[i].Right_chlid = 0;
            HT[i].parent = 0;
        }
        for (int i = 1; i <= n;++i)
        {
            std::cin >> HT[i].weight;
        }
    }
}

void CreatHuffmanCode(Huffman_tree HT,HtNode &H,int n)
{

} 