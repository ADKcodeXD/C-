#include<stdio.h>
#include<stdlib.h>
#define maxsize 9
#define MAX 99
#define Vertex int
#define ptype int
#define datatype char
typedef struct enode *edge;
struct enode{
    Vertex V1,V2;
};
typedef struct gnode *mg;
struct gnode{
    int ne;
    int nv;
    char node[maxsize];
    ptype G[maxsize][maxsize];
    int visited[maxsize];
};
mg create(int num){
    Vertex V,W;
    int i;
    mg graph;
    graph=(mg)malloc(sizeof(struct gnode));
    graph->ne=0;
    graph->nv=num;
    for (V=0;V<graph->nv;V++){
        for (W=0;W<graph->nv;W++){
            graph->G[V][W]=MAX;
        }
    }
    for(i=0;i<graph->nv;i++){
        graph->visited[i]=0;
    }for(i=0;i<graph->nv;i++){
        graph->node[i]='z';
    }
    return graph;
}
void print(mg graph){
    int i;int j;
    printf("   ");
    for (i=0;i<graph->nv;i++){
        printf("[%c]",graph->node[i]);
    }
    for (i=0;i<graph->nv;i++){
        for(j=0;j<graph->nv;j++){
            if(j==0){
                printf("\n");
                printf("[%c]",graph->node[i]);
            }
            printf("[%d]",graph->G[i][j]);
        }
    }
}
mg insert(mg graph,edge E,int weight){
    graph->G[E->V1][E->V2]=weight;
    graph->G[E->V2][E->V1]=weight;
}
int get_node_index(char a,mg graph){
    int i ;
    for (i=0;i<graph->nv;i++){
        if (graph->node[i]==a)
            return i;
    }
    return 0;
}
mg build(){
    int Nv;int i,c;char a,b;
    scanf("%d",&Nv);
    if(Nv==0){
        return ;
    }
    if(Nv>=maxsize){
    	printf("超过最大限制！\n");
    	scanf("%d",&Nv);
    }
    mg graph=create(Nv);
    scanf("%d",&graph->ne);
    fflush(stdin);
    i=0;
    if(graph->nv){
    while(i<graph->nv){
        scanf("%c,",&graph->node[i]);
        i++;
    }
    }
    if(graph->ne!=0){
        int j;
        edge E=(edge)malloc(sizeof(struct enode));
           for(j=0;j<graph->ne;j++){
               fflush(stdin);
               scanf("%c,%c,%d",&a,&b,&c);
               getchar();
               E->V1=get_node_index(a,graph);
               E->V2=get_node_index(b,graph);
               insert(graph,E,c);
        }
    }
    return graph;
}
void prim(mg graph,int u){
    int mst[graph->nv];
    int lowcost[graph->nv];
	int i,j;int sum;
	for(i=0;i<graph->nv;i++){
		mst[i]=u;
		lowcost[i]=graph->G[u][i];
	}
	mst[u]=0;
	for(i=1;i<graph->nv;i++){
		int min=MAX;
		Vertex V=0;
		for (j=1;j<graph->nv;j++){
			if(lowcost[j]!=0 && lowcost[j]<min){
				min = lowcost[j];
				V=j;
			}
		}
		if(i==graph->nv-1)
		printf("%c,%c,%d",graph->node[mst[V]],graph->node[V],min);
		else
		printf("%c,%c,%d\n",graph->node[mst[V]],graph->node[V],min);
		sum+=min;
		lowcost[V]=0;
		for(j=1;j<graph->ne;j++){
			if(graph->G[V][j]<lowcost[j]){
				lowcost[j]=graph->G[V][j];
				mst[j]=V;
			}
		}
	}
}
void main(){
    mg graph=build();
    if (graph==NULL){
        return;
    }
    prim(graph,0);
}
