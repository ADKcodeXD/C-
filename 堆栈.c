#include<stdio.h>
#include<stdlib.h>
#define maxsize 50
typedef struct stack *Stack;
struct stack
{
	char data[maxsize];
	int top;
};
Stack createStack(){
	Stack new;
	new=(char *)malloc(sizeof(char)*maxsize);
	new->top=-1;
	return new;
}
void Push(Stack P,char item){
	if (P->top==maxsize-1){
		printf("¶ÑÕ»Âú\n");
		return ;
	}
	else{
		P->data[++P->top]=item;
		return ;
	}
}
void Pop(Stack P,char *e){
	if(P->top==-1){
		printf("¶ÑÕ»¿Õ\n");
		return ;
	}else{
		char t = P->data[P->top];
		P->top--;
		*e=t;
	}
}
int SEmpty(Stack p){
	if(p->top==-1){
		return 1;
	}else
	return 0;
}
void main(){
	Stack S=createStack();
	char x,y;
	x='c';y='k';
	Push(S,x);
	Push(S,'a');
	Push(S,y); 
	Pop(S,&x);  
	Push(S,'t'); 
	Push(S,x);
	Pop(S,&x);
	Push(S,'s'); 
	while (!SEmpty(S)) 
	{ 
	  Pop(S,&y);
	  printf("%c",y); 
	} 
	printf("%c",x); 
}
