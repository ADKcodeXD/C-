#include <stdio.h>
#include <stdlib.h>
#define ElementType int
struct node{
	ElementType num;
	struct node *next;
};
typedef struct node *linkQueue,node;
linkQueue init(){
	rear=(linkQueue)malloc(sizeof(struct node));
	rear->next=rear;
	return rear;
}
int isEmpty(Queue q){
	if (q->rear->next=q->rear) return 1;
	else return 0;
}
void AddQ(Queue q,ElementType data){
	linkQueue p;
//	p=(linkQueue)malloc(sizeof(struct node));
//	p->num=data;
//	p->next=q->rear->next;
//	q->rear->next=p;
//	q->rear=p;
//	q->length++;
	p=(linkQueue)malloc(sizeof(struct node));
	p->num=data;
	p->next=q->rear->next; 
	q->rear->next=p;
	q->rear=p;
}
ElementType DeleteQ(Queue q){
	if (!isEmpty){
		return 0;
	}
	
	
}
void print(Queue q){
	Queue p=q;
	while(p->rear->next!=p->rear){
		p->rear->next=p->rear->next->next;
		printf("%d ",p->rear->next->num);
	}
}

void main(){
	Queue q=init();
	int a,i,num,b,h;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf ("%d",&num);
		AddQ(q,num);
	}
	print(q);
	printf("\n");
	scanf("%d",&b);
	for (i=0;i<b;i++){
		h=DeleteQ(q);
		printf("h is %d",h);
	}
	print(q);
	
}
