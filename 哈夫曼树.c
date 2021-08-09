#include<stdio.h>
#include<stdlib.h>
#define maxsize 50
typedef struct hufftree *HT;
struct hufftree{
	int weight;
	HT left,right;
	HT next;
	int flag;
}; 
HT createlink(int n){
	HT link,p,q,s,first;
	int i;
	link=(HT)malloc(sizeof(struct hufftree));
	first=(HT)malloc(sizeof(struct hufftree));
	//输入首个结点的权值 
	scanf("%d",&first->weight);
	first->left=NULL;
	first->right=NULL;
	first->next=NULL;
	link->next=first;
	for (i=2;i<=n;i++){
		p=(HT)malloc(sizeof(struct hufftree));
		scanf("%d",&p->weight);
		p->left=NULL;
		p->right=NULL;
		q=link;
		s=q->next;
		while(s){
			if(p->weight>s->weight){
				q=s;
				s=s->next;
			}else{
				q->next=p;
				p->next=s;
				break;
			}
			if(s==NULL && p->weight>q->weight){
				q->next=p;
				p->next=s;
			}
		}
	}
	return link;
}
void print(HT link){
	HT temp=link;
	while(temp->next){
		temp=temp->next;
		printf("%d ",temp->weight);
		
	}
} 
HT bulidtree(HT link){
	HT a,b,c;
	while(link->next){
		a=link->next;
		b=a->next;
		link->next=b->next;
		c=(HT)malloc(sizeof(struct hufftree));
		c->left=a;
		c->right=b;
		c->weight=a->weight+b->weight;
		a=link;
		b=a->next;
		while(b){
			if(c->weight>b->weight){
				a=b;
				b=b->next;
			}else{
				a->next=c;
				c->next=b;
				break;
			}if(b==NULL && c->weight>a->weight){
				a->next=c;
				c->next=b;
			}
		}
	}
	return c;
}
void midorder(HT T){
	if(T){
		midorder(T->left);
		printf("%d ",T->weight);
		midorder(T->right);
		
	}
}
HT huffmancode(HT p){
	int i=-1,j=0,flag,k,code[maxsize];
	HT stack[maxsize],q;
	do
	{
		while(p){
			if(p->left==NULL&&p->right==NULL){
				for(k=0;k<j;k++){
					printf("%d",code[k]);
				}
				printf(" ");
				j--;
			}
			stack[++i]=p;
			code[j++]=1;
			p=p->left;
		}
		q=NULL;
		flag=1;
		while(flag&&i>=0){
			p=stack[i];
			if(p->right==q){
				i--;
				j--;
				q=p;
			}
			else{
				p=p->right;
				code[j++]=0;
				flag=0;
			}
		}
	}while(i>=0);
}
void main(){
	int a;
	scanf("%d",&a);
	HT link=createlink(a);
	HT tree=bulidtree(link);
	huffmancode(tree);
}
