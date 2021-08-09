#include<stdio.h>
#include<stdlib.h>
#define nameMAXSIZE 10
typedef struct Lnode *List;
struct Lnode{
	int num;
	int point;
	char *name;
	List Next;
};
List Listinit(){
	List p;
	p=(List)malloc(sizeof(List));
	printf("%d\n",sizeof(List));
	if(!p){
		printf("申请失败！\n");
	}
	p->Next=NULL;
	return p;
}
int inputdata(List head){
	List N;
	N=(List)malloc(sizeof(List)/sizeof(char));
	N->Next=NULL;
	N->name=malloc(sizeof(char)*nameMAXSIZE);
	printf("请输入姓名 ："); 
	scanf("%s",N->name);
	printf("请输入学号：") ;
	scanf("%d",&N->num);
	printf("请输入分数(输入-1结束输入)：") ;
	scanf("%d",&N->point);
	if(N->point==-1){
		return 0;
	}
	List temp=head;
	while(temp->Next){
		temp=temp->Next;
	}
	temp->Next=N;
	return 1;
}
void Insert(List h){
	int i;int j;
	printf("请输入你要插入的位置：");
	scanf("%d",&i);
	List new;
	new=(List)malloc(sizeof(List)/sizeof(char));
	new->Next=NULL;
	new->name=malloc(sizeof(char)*nameMAXSIZE);
	printf("请输入姓名 ："); 
	scanf("%s",new->name);
	printf("请输入学号：") ;
	scanf("%d",&new->num);
	printf("请输入分数：") ;
	scanf("%d",&new->point);
	List temp = h;
	List temp2 =h;
	for (j=0;j<i-1;j++)
		temp=temp->Next;
	for (j=0;j<i+1;j++)
		temp2=temp->Next;
	temp->Next=new;
	new->Next=temp2;
}
void Delete(List h){
	int i;int j;
	printf("请输入你要删除的位置：") ;
	scanf("%d",&i);
	List temp=h;
	List temp2=h;
	for(j=0;j<i;j++)
		temp=temp->Next;
	for(j=0;j<i-1;j++)
		temp2=temp2->Next;
	temp2->Next=temp->Next;
	free(temp);
}
int length(List head){
	int j=0;
	List temp=head;
	while (temp->Next){
		temp=temp->Next;
		j++;
	}
	return j;
}
void printDATA(List head){
	List temp=head;
	int j=1;
	while(temp->Next){
		temp=temp->Next;
		printf("第%d名学生的姓名是：%s，学号是：%d，分数是：%d。\n",j,temp->name,temp->num,temp->point);
		j++;
	}
}
int main(){
	List head=Listinit();
	while(inputdata(head)){
		
	}
	printDATA(head);
	Insert(head);
	printDATA(head);
	Delete(head);
	printDATA(head);
	printf("%d",length(head));
	
}
