#include<stdio.h>
#include<stdlib.h>
#define ElementType int
// 树的数据结构 ！
typedef struct stacknode *Stack;
typedef struct Treenode *Bintree;
struct Treenode
{
	ElementType data;
	Bintree left;
	Bintree right;
};
struct stacknode
{
	
};
//先序递归 遍历
void preorderTraversal(Bintree bt){
	if(bt){
		printf("%d\n",bt->data);
		preorderTraversal(bt->left);
		preorderTraversal(bt->right);
	}
}
//中序递归
void inorderTraversal(Bintree bt){
	if(bt){
		inorderTraversal(bt->left);
		printf("%d\n",bt->data);
		inorderTraversal(bt->right);
	}
}
//后序
void postorderTraversal(Bintree bt){
	if(bt){
		postorderTraversal(bt->left);
		postorderTraversal(bt->right);
		printf("%d\n",bt->data);
	}
}
//堆栈stack可以实现非递归的中序遍历
