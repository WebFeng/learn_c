#include <stdio.h>
//顶点数
#define VERTEX_NUM 6
#define INT_MAX  1000

//顶点
typedef int VertexType;

//存储边上的权值
typedef struct{
    int adj;
}Adj;

//连通图
typedef struct{
	//顶点集合
    VertexType vexs[VERTEX_NUM];
	//矩阵图
    Adj arcs[VERTEX_NUM][VERTEX_NUM];
	//顶点数,==VERTEX_NUM
    int vexnum;
} MGraph;

//最近的边
typedef struct{
	//邻接域
    VertexType adjvex;
	//最低成本
    int lowcost;
} closedge;

VertexType vertexs[]={1,2,3,4,5,6};
int weight[][VERTEX_NUM]={{1000,6,1,5,1000,1000},{6,1000,5,1000,3,1000},{1,5,1000,5,6,4},
        {5,1000,5,1000,1000,2},{1000,3,6,1000,1000,6},{1000,1000,4,2,6,1000}};
int InitG(MGraph *G);
void MiniSpanTree_PRIM(MGraph G,VertexType u);
int mininum(closedge cdge[]);
int LocateVex(MGraph G,VertexType u);

int main(void){
    int i;
    MGraph G;
    i=InitG(&G);
    MiniSpanTree_PRIM(G,6);
	return 0;
}

//初始化图
int  InitG(MGraph *G){
    int i,j;
    G->vexnum=VERTEX_NUM;
    for(i=0;i<G->vexnum;i++)
        G->vexs[i]=vertexs[i];
    for(i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j].adj=weight[i][j];
    return 1;
}

void MiniSpanTree_PRIM(MGraph G,VertexType u)
{
    int k, i, j;

    closedge cdge[VERTEX_NUM];
    k = LocateVex(G,u);

    for (j = 0; j < G.vexnum; j++)
        if (j != k) {
            cdge[j].adjvex = u;
            cdge[j].lowcost = G.arcs[k][j].adj;
        }

    //初始,U={u};
    cdge[k].lowcost = 0;

	//选择其余G.vexnum-1个顶点
    for (i=1; i<G.vexnum; i++) {                
 		//求出T的下一个节点:第K顶点
        k = mininum(cdge);           
        printf("%d-%d\n", cdge[k].adjvex, G.vexs[k]);
        cdge[k].lowcost = 0;
        for (j = 0; j < G.vexnum; j++)
            if (G.arcs[k][j].adj < cdge[j].lowcost) {
                cdge[j].adjvex = G.vexs[k];
                cdge[j].lowcost = G.arcs[k][j].adj;
            }
    }
}

int LocateVex(MGraph G,VertexType u){
    int i;
    for(i=0;i<VERTEX_NUM;i++)
        if(G.vexs[i]==u)return i;
    return -1;
}

//求出closedge中最小的权值
int mininum(closedge cdge[])
{
    int i, j, k;
    i = INT_MAX;
    for (j = 0; j < VERTEX_NUM; j++)
        if (cdge[j].lowcost != 0 && cdge[j].lowcost != INT_MAX)
            if (cdge[j].lowcost < i) {
                i = cdge[j].lowcost;
                k = j;
            }
    return k;
}


