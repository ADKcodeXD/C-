#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define maxsize 50
typedef struct STREE *Stree; 
struct STREE
{
	char data;
	Stree left;
	Stree right;
};
Stree input(Stree T){
	char data;
	scanf("%c",&data);
	getchar();
	if (data=='#'){
		T=NULL;
		printf("�������--- %c \n",data);
	}else{
		T=(Stree)malloc(sizeof(struct STREE));
		printf("������---%c \n",data); 
		T->data=data;
		T->left=input(T->left);
		T->right=input(T->right);
	}
	printf("���ؿ���"); 
	return T;
}
void inorder(Stree bt){
	if (bt){
		printf("%c ",bt->data);
		inorder(bt->left);
		inorder(bt->right);
	}
}
void main(){
	Stree p;
	p=input(p);
	printf("��ʼ����!");
	inorder(p);
}
