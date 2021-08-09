#include<stdio.h>
#include<stdlib.h>
#define ElmentType int
typedef struct Lnode *List;
struct Lnode
{
	ElmentType value;
	List next;
};
int length;
void Find(List p,ElmentType x){
	List temp=p;
	while(temp){
		if (temp->value==x)
		{
			printf("Found!\n");
			return;
		}
	temp=temp->next;
	}
	printf("Not Found!\n");
}
void Insert(List p,int index,ElmentType x){
	int i;
	//if(index>=length){
		//printf("The given position is invalid!\n");
        //return;
	//}
	if(index<=0){
		printf("The given position is invalid!\n");
        return;
	}
	List new;
	new=(List)malloc(sizeof(List));
	new->value=x;
	List temp=p;
	for(i=0;i<index-1;i++){
		temp=temp->next;
		if(temp->next==NULL){
			break;
		}
	}
	new->next=temp->next;
	temp->next=new;
	length++;
}
List init(){
	List p;
	p=(List)malloc(sizeof(List));
	p->next=NULL;
	length=0;
	return p;
}
void input(List p){
	List temp;
	temp=(List)malloc(sizeof(List));
	temp->next=NULL;
	length++;
	scanf("%d",&temp->value);
	List temp2=p;
	while(temp2->next){
		temp2=temp2->next;
	}
	temp2->next=temp;
}
void print(List p){
	List temp=p;
	while(temp->next){
		temp=temp->next;
		printf("%d ",temp->value);
	}
	printf("\n");
}
List delete(List p,ElmentType t){
	List temp=p;
	List temp2=temp;
	while(temp->next){
		if(temp->value==t){
			temp2->next=temp->next;
			free(temp);
			return;
		}
		temp2=temp;
		temp=temp->next;
	}
	length--;
}
void main(){
	int a;int i;
	List p=init();
	scanf("%d",&a);
	for (i=0;i<a;i++){
		input(p);
	}
	print(p);
	Find(p,30);
	Find(p,67);
	Insert(p,5,12);
	print(p);
	Insert(p,10,18);
	print(p);
	delete(p,10);
	print(p);
}
