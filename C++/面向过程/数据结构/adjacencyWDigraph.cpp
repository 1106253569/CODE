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

template <typename T>
class adjacencyWDigraph : public graph<T>
{
protected:
    //顶点个数
    int n;
    //边的个数
    int e;
    //邻接数组
    T **a;
    //表示不存在的边
    T noEdge;

public:
    //构造函数
    adjacencyWDigraph(int numberOfVertices = 0, T theNoEdge = 0)
    {
        //确认顶点数的合法性
        if (numberOfVertices < 0)
            throw std::illegalParameterValue("number of vertices must be >= 0");
        n = numberOfVertices;
        e = 0;
        noEdge = theNoEdge;
        make2dArray(a, n + 1, n + 1);
        //初始化邻接矩阵
        for (int i = 1; i <= n; i++)
            fill(a[i], a[i] + n + 1, noEdge);
    }
    ~adjacencyWDigraph() { delete2dArray(a, n + 1); }
};