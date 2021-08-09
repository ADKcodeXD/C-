#include<stdio.h>
#include<stdlib.h>
#define maxsize 50
typedef struct Lnode *List;
struct Lnode
{
	int data[maxsize];
	int length;
};
List create(){
	List a=(List)malloc(sizeof(struct Lnode));
	a->length=0; 
	return a;
}
void input(List P){
	int a,i,number;
	scanf("%d",&a);
	P->length=a;
	for (i=0;i<P->length;i++){
	scanf("%d",&number);
	P->data[i]=number;

	}
}
void print(List P){
	int i=0;
	while(i<P->length){
		printf("%d ",P->data[i]);
		i++;
	}
}
void nixu(List P){
	int t,i;
	for (i=0;i<P->length/2;i++){
		t=P->data[i];
		P->data[i]=P->data[P->length-i-1];
		P->data[P->length-i-1]=t;
	}
}
void main(){
	List a=create();
	input(a);
	printf("\n");
	nixu(a);
	print(a);
	
}
