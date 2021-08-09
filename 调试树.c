#include<stdio.h>
#include<stdlib.h>
#define ElementType int

#define maxsize 50
// �������ݽṹ ��
typedef struct Treenode *Bintree;
typedef struct stacknode *Stack;
struct stacknode
{
	Bintree data[maxsize];
	int top;
};
Stack createStack(){
	Stack new;
	new=(Bintree*)malloc(sizeof(Bintree)*maxsize);
	new->top=-1;
	return new;
}
void Push(Stack P,Bintree item){
	if (P->top==maxsize-1){
		printf("��ջ��\n");
		return ;
	}
	else{
		P->data[++P->top]=item;
		return ;
	}
}
Bintree Pop(Stack P){
	if(P->top==-1){
		printf("��ջ��\n");
		return ;
	}else{
		Bintree t = P->data[P->top];
		P->top--;
		return t;
	}
}
int SEmpty(Stack p){
	if(p->top==-1){
		return 1;
	}else
	return 0;
}

struct Treenode
{
	ElementType data;
	Bintree left;
	Bintree right;
};
//����ݹ� ����
void preorderTraversal(Bintree bt){
	if(bt){
		printf("%d\n",bt->data);
		preorderTraversal(bt->left);
		preorderTraversal(bt->right);
	}
}
//����ݹ�
void inorderTraversal(Bintree bt){
	if(bt){
		inorderTraversal(bt->left);
		printf("%d\n",bt->data);
		inorderTraversal(bt->right);
	}
}
//����
void postorderTraversal(Bintree bt){
	if(bt){
		postorderTraversal(bt->left);
		postorderTraversal(bt->right);
		printf("%d\n",bt->data);
	}
}
//��ջstack����ʵ�ַǵݹ���������
void inorderTraversalStack(Bintree bt){
	Stack a=createStack();
	while (bt||!SEmpty(a)){
		while(bt){
			Push(a,bt);
			bt=bt->left;
		}
		if(!SEmpty(a)){
			Bintree T=Pop(a);
			printf("%.5d\n",T->data);
			T=T->right;
		}
	}
}
void main(){
	
}
