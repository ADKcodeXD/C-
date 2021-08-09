#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
typedef int QElemType;
typedef struct Lnode{
    QElemType data;
    struct Lnode *next;
}Node,*Queue;
int count;
Queue init(){
	Queue rear=(Queue)malloc(sizeof(Node));
	rear->next=rear;
	return rear;
}
Queue AddQ(Queue rear,QElemType x){
	if (count>Maxsize){
		printf("¶ÑÕ»ÒÑÂú£¡");
		return ;
	}
	Queue p;
	p=(Queue)malloc(sizeof(Node));
	p->data=x;
	p->next=rear->next;
	rear->next=p;
	rear=p;
	count++;
	return rear;
}
Queue DeleteQ(Queue rear){
	if(rear=rear->next){
		printf("¶ÑÕ»¿Õ£¡");
		return;
	}
	Queue p;
	p=rear->next->next;
	rear->next->next=p->next;
	free(p);
	count--;
	return rear;
}
void print(Queue rear){
	Queue p=rear->next;
	while(p!=rear){
		p=p->next;
		printf("%d ",p->data);
	}
}
int main(){
	Queue rear=init();
	int i,a,b,*temp;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		QElemType h;
		scanf("%d",&h);
		rear=AddQ(rear,h);
	}
	print(rear);
	printf("\n");
	scanf("%d",&b);
	for(i=0;i<b;i++)
	DeleteQ(rear);
	print(rear);
	return 0; 
}
