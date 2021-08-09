#include<stdio.h>
#include<stdlib.h>
#define ptype int
#define datatype char
#define maxsize 20
#define Vertex int
typedef int QElemType;
typedef struct qnode{
    int *data;
    int rear;
    int front;
}*Queue;
Queue init(){
	Queue q=(Queue)malloc(sizeof(struct qnode));
	q->data=malloc(sizeof(int)*maxsize);
	q->rear=0;
	q->front=0;
	return q;
}
void AddQ(Queue q,int x){
	if (q->rear>maxsize){
		printf("堆栈已满！");
		return ;
	}
	q->data[q->rear]=x;
	q->rear++;
}
int DeleteQ(Queue q){
	if(q->rear==0){
		printf("堆栈空！");
		return;
	}
	int temp,i;
	temp=q->data[q->front];
	for(i=0;i<q->rear;i++){
		q->data[i]=q->data[i+1];
	}
	q->rear--;
	return temp;
}
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
            graph->G[V][W]=0;
        }
    }
    for(i=0;i<graph->nv;i++){
        graph->visited[i]=0;
    }for(i=0;i<graph->nv;i++){
        graph->node[i]='z';
    }
    return graph;
}
mg insert(mg graph,edge E){
    graph->G[E->V1][E->V2]=1;
    graph->G[E->V2][E->V1]=1;
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
    int Nv;int i;char a,b;
    scanf("%d",&Nv);
    if(Nv==0||Nv>maxsize){
    	return ;
    } 
    mg graph=create(Nv);
    scanf("%d",&graph->ne);
    if(graph->ne==0||graph->ne>Nv-1){
    	return;
    } 
    fflush(stdin);
    i=0;
    if(graph->nv){
    while(i<graph->nv){
        //printf("请输入第%d个节点:",i+1);
        scanf("%c",&graph->node[i]);
        i++;
    }
	}
    if(graph->ne!=0){
        int j;
        edge E=(edge)malloc(sizeof(struct enode));
           for(j=0;j<graph->ne;j++){
               fflush(stdin);
               scanf("%c,%c",&a,&b);
               getchar();
               E->V1=get_node_index(a,graph);
               E->V2=get_node_index(b,graph);
               insert(graph,E);
        }
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
void DFS(mg graph,Vertex V){
	int i;
	graph->visited[V]=1;
	printf("%c",graph->node[V]);
	for(i=0;i<graph->nv;i++){
		if(graph->G[V][i]!=0 && graph->visited[i]==0)
			DFS(graph,i);
	}
}
void visitedinit(mg graph){
	int i;
	for(i=0;i<graph->nv;i++){
        graph->visited[i]=0;
    }
}
void BFS(mg graph,Vertex V){
	int i;
	graph->visited[V]=1;
	printf("%c",graph->node[V]);
	Queue q=init();
	AddQ(q,V);
	while(q->rear!=0){
		V=DeleteQ(q);
		for(i=0;i<graph->nv;i++){
			if(graph->G[V][i]!=0 && graph->visited[i]==0){
					graph->visited[i]=1;
					printf("%c",graph->node[i]);
					AddQ(q,i);
			}
		}
	}
}
void main(){
    mg graph=build();
    if (graph==NULL){
    	return;
    }
    printf("输出结果:\n");
    DFS(graph,0);
    printf("\n");
    visitedinit(graph);
    BFS(graph,0); 
}
