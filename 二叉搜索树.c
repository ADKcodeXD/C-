#include <stdio.h>
#include <stdlib.h>
typedef struct treenode *BST;
struct treenode
{
	int data;
	BST left;
	BST right;
};
BST init(){
	int data;
	BST T;
	scanf("%d",&data);
	if (data==-1){
		T=NULL;
	}else{
		T=(BST)malloc(sizeof(struct treenode));
		T->data=data;
		T->left=NULL;
		T->right=NULL;
	}
	return T;
}
BST insert(int data,BST T){
	if(!T){
		T=(BST)malloc(sizeof(struct treenode));
		T->data=data;
		T->left=T->right=NULL;
	}else{
		if(data>T->data){
			T->right=insert(data,T->right);
		}else if(data<T->data){
			T->left=insert(data,T->left);
		}
	}
	return T;
}
BST find(int x,BST T){
	while(T){
		if (x>T->data){
			T=T->right;
		}else if(x<T->data){
			T=T->left;
		}else
		return T;
	}
	return NULL;
}
BST Findmin(BST T){
	while(T->left){
		T=T->left;
	}
	return T;
}
BST Delete(int X,BST T){
	BST temp;
	if (!T){
		printf("Î´ÕÒµ½ÔªËØ!\n");
	}else{
		if(X>T->data){
			T->right=Delete(X,T->right);
		}else if(X<T->data){
			T->left=Delete(X,T->left);
		}else{
			if(T->left && T->right){
				temp=Findmin(T->right);
				T->data=temp->data;
				T=Delete(T->data,T->right);
			}else{
				temp=T;
				if (!T->left){
					T=T->right;
				}else if(!T->right){
					T=T->left;
				}
			}
		}
	}
	return T;
}
void midorder(BST T){
	if (T){
		midorder(T->left);
		printf("%d ",T->data);
		midorder(T->right);
	}
}
int height(BST T){
	int h1;
	int h2;
	if (!T){
		return 0;
	}else{
		h1=height(T->left);
		h2=height(T->right);
		return h1>h2?++h1:++h2;
	}
}
void main(){
	BST T;
	int data;
	T=(BST)malloc(sizeof(struct treenode));
	T=init();
	while(1){
		scanf("%d",&data);
		if (data==-1){
			break;
		}else
		T=insert(data,T);
	}
	midorder(T);
	printf("\n");
	Delete(20,T);
	midorder(T);
	printf("\n");
	int a=height(T);
	printf("%d\n",a);
	printf("%d,%d",height(T->left),height(T->right));
}
