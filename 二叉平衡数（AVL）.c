#include <stdio.h>
#include <stdlib.h>
typedef struct treenode *BST;
struct treenode
{
	int data;
	BST left;
	BST right;
	int height;
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
void midorder(BST T){
	if (T){
		midorder(T->left);
		printf("%d ",T->data);
		midorder(T->right);
	}
}
void preorder(BST T){
	if (T){
		printf("%d ",T->data);
		preorder(T->left);
		preorder(T->right);
	}
}
BST RR(BST T){
	BST A=T;
    BST B=T->right;
    A->right=B->left;
    T=B;
    B->left=A;
	return T; 
}
BST RL(BST T){
	BST A=T;
	BST B=T->right;
	BST C=B->left;
	A->right=C->left;
	B->left=C->right;
	C->left=A;
	C->right=B;
	T=C;
	return T; 
}
BST LR(BST T){
	BST A=T;
	BST B=T->left;
	BST C=B->right;
	A->left=C->right;
	B->right=C->left;
	C->left=B;
	C->right=A;
	T=C;
	return T; 
}
BST LL(BST T){
    BST A=T;
    BST B=T->left;
    A->left=B->right;
    T=B;
    B->right=A;
    return B;
}
BST insert(BST T,int data){
	if (!T){
		T=(BST)malloc(sizeof(struct treenode));
		T->data=data;
		T->left=T->right=NULL;
		T->height=0;
	}
	else if (data<T->data){
		T->left=insert(T->left,data);
		if (height(T->left)-height(T->right)==2){
			if (data<T->left->data){
				T=LL(T);
			}else if (data>T->left->data){
				T=LR(T);
			}
		}
	}else if (data>T->data){
		T->right=insert(T->right,data);
		if (height(T->right)-height(T->left)==2){
			if (data>T->right->data){
				T=RR(T);
			}else if (data<T->right->data){
				T=RL(T);
			}
		}
	}
	return T;
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
		T=insert(T,data);
	}
	preorder(T);
	printf("\n");
	midorder(T);
	printf("\n");
	printf("%d",height(T->right)-height(T->left));
}
