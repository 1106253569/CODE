#include <iostream>

template <typename T>
class graph
{
public:
    virtual ~graph();
    //ADT
    //返回顶点数
    virtual int numberOfVertices() const = 0;
    //返回边数
    virtual int numberOfEages() const = 0;
    //判断指定边（x，y）是否存在
    virtual bool existsEdge(int, int) const = 0;
    //删除指定边
    virtual void insertEdge(edge<T> *) = 0;
    //删除边
    virtual void eraseEdge(int, int) = 0;
    //返回无向图的边
    virtual int degree(int) const = 0;
    //返回入度
    virtual int inDegree(int) const = 0;
    //返回出度
    virtual int outDegree(int) const = 0;
    //other
    //判断是否为有向图
    virtual bool directed() const = 0;
    //判断是否为加权图
    virtual bool weighted() const = 0;
    //访问指定顶点的相邻顶点
    virtual vertexIterator<T> *iterator(int) = 0;
};


