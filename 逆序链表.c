#include<stdio.h>
#include<stdlib.h>
typedef struct Line *La;
int a;
#define anytype int
struct Line{
	anytype data;
	La next;
};
La null_la(){
	La null_la=(La)malloc(sizeof(La));
	null_la->next=NULL;
	null_la->data=-1;
	return null_la;
}
void create_la(anytype data,La head){
	La a=(La)malloc(sizeof(La));
	a->data=data;
	a->next=NULL;
	La temp=head;
	while (temp->next){
		temp=temp->next;
	}
	temp->next=a;
}
La input(){
	int i;
	scanf("%d",&a);
	La head=null_la();
	anytype data;
	for (i=0;i<a;i++){
		scanf("%d",&data);
		create_la(data,head);
	}
	return head;
}
void nixu(La head){
	La prev=NULL;
	La temp;
	while(head->next){
		temp=head->next;
		head->next=temp->next;
		temp->next=prev;
		prev=temp;
	}
	head->next=prev;
}
void print(La head){
	La temp=head;
	while (temp->next){
		if(temp->data==-1){
			;
		}
			else{
				printf("%d ",temp->data);
			}
		temp=temp->next;
	}
	printf("%d ",temp->data);
}
void main(){
	La head=input();
	print(head);
	nixu(head);
	printf("\n");
	print(head);	
}
