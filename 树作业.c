#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ElementType char
#define max 50
typedef struct treenode *Bintree; 
struct treenode{
	ElementType data;
	Bintree left;
	Bintree right;
};
//新建节点 
Bintree newnode(){
	Bintree new1=(Bintree )malloc(sizeof(struct treenode));
	new1->data=0;
	new1->left=new1->right=NULL;
	return new1;
}
//后序
void postorderTraversal(Bintree bt){
	if(bt){
		postorderTraversal(bt->left);
		postorderTraversal(bt->right);
		printf("%c",bt->data);
	}
}
//根据序列建二叉树
 Bintree bulid(int n,char *s1,char *s2){
 	if (n<=0){
 		return NULL;
 	}
 	Bintree t=newnode();
 	t->data=s1[0];
 	int p=strchr(s2,s1[0])-s2;
 	
 	t->left=bulid(p,s1+1,s2);
 	t->right=bulid(n-1-p,s1+1+p,s2+p+1);
 	
 	return t;
 }
//输入数据 
Bintree input(){
	char s1[max],s2[max];
	scanf("%s",s1);
	scanf("%s",s2);
	int n=strlen(s1);
	Bintree t=bulid(n,s1,s2);
	return t;
}
void main(){
	Bintree t=input();
	postorderTraversal(t);
	printf("\n");
}
