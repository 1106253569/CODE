#include <iostream>
#define MaxNum 100
typedef char VerTexType;
typedef int ArcType;
struct AMGraph
{
    VerTexType vexs[MaxNum];
    ArcType arcs[MaxNum][MaxNum];
    int Vex_num;
    int Arc_num;
};

void Create_UDM(AMGraph &G)
{
    std::cin >> G.Vex_num >> G.Arc_num;
    for (int i = 0; i < G.Vex_num;++i)
    {
        std::cin >> G.vexs[i];
    }
    for (int i = 0; i < G.Vex_num;++i)
        for (int j = 0; j < G.Vex_num;++j)
            G.arcs[i][j] = MaxNum;
    for (int k = 0; k < G.Arc_num;++k)
    {
        VerTexType v1, v2;
        int w;
        std::cin >> v1 >> v2 >> w;
        int i = Locate_vex(G, v1);
        int j = Locate_vex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
}

int Locate_vex(AMGraph G,VerTexType u)
{
    for (int i = 0; i < G.Vex_num;++i)
    {
        if(u==G.vexs[i])
            return -1;
    }
}