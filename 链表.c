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
		printf("����ʧ�ܣ�\n");
	}
	p->Next=NULL;
	return p;
}
int inputdata(List head){
	List N;
	N=(List)malloc(sizeof(List)/sizeof(char));
	N->Next=NULL;
	N->name=malloc(sizeof(char)*nameMAXSIZE);
	printf("���������� ��"); 
	scanf("%s",N->name);
	printf("������ѧ�ţ�") ;
	scanf("%d",&N->num);
	printf("���������(����-1��������)��") ;
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
	printf("��������Ҫ�����λ�ã�");
	scanf("%d",&i);
	List new;
	new=(List)malloc(sizeof(List)/sizeof(char));
	new->Next=NULL;
	new->name=malloc(sizeof(char)*nameMAXSIZE);
	printf("���������� ��"); 
	scanf("%s",new->name);
	printf("������ѧ�ţ�") ;
	scanf("%d",&new->num);
	printf("�����������") ;
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
	printf("��������Ҫɾ����λ�ã�") ;
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
		printf("��%d��ѧ���������ǣ�%s��ѧ���ǣ�%d�������ǣ�%d��\n",j,temp->name,temp->num,temp->point);
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
