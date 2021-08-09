//多项式相乘相加
#include<stdio.h>
#include<stdlib.h>
typedef struct duoxiangshi *dxs;
struct duoxiangshi
{
	int xishu;
	int zhishu;
	dxs next;
};
void Attach(int c,int d,dxs *rear){
	dxs P;
	P=(dxs)malloc(sizeof(dxs));
	P->xishu=c;
	P->zhishu=d;
	P->next=NULL;
	(*rear)->next=P;
	*rear=P;
}
dxs readonly(){
	dxs P,rear,t;
	int N;int c,d;
	scanf("%d",&N);
	P=(dxs)malloc(sizeof(dxs));
	P->next=NULL;
	rear=P;
	while(N--){
		printf("请输入下一个数值的系数和指数\n");
		scanf("%d %d",&c,&d);
		Attach(c,d,&rear);
	}
	t=P;P=P->next;free(t);
	return P;
}
dxs Add(dxs p1,dxs p2){
	dxs t1,t2;
	t1=p1;t2=p2;
	dxs P,rear,t;
	P=(dxs)malloc(sizeof(dxs));
	rear=P;
	while(t1&&t2){
		if(t1->zhishu==t2->zhishu){
			Attach((t1->xishu+t2->xishu),t1->zhishu,&rear);
			t1=t1->next;
			t2=t2->next;
		}else if (t1->zhishu>t2->zhishu)
		{
			Attach(t1->xishu,t1->zhishu,&rear);
			t1=t1->next;
		}else 
		{
			Attach(t2->xishu,t2->zhishu,&rear);
			t2=t2->next;
		}
	}
	while(t1){
		Attach(t1->xishu,t1->zhishu,&rear);
		t1=t1->next;
	}
	while(t2){
		Attach(t2->xishu,t2->zhishu,&rear);
		t2=t2->next;
	}
	t=P;P=P->next;free(t);
	return P;
}
void Print(dxs P){
	dxs temp=P;
	while(temp->next){
		printf("%dX(%d)+",temp->xishu,temp->zhishu);
		temp=temp->next;
	}
	printf("%dX(%d)",temp->xishu,temp->zhishu);
	printf("\n");
}
dxs Mulit(dxs p1,dxs p2){
	dxs t1=p1;dxs t2=p2;
	dxs P=(dxs)malloc(sizeof(dxs));
	P->next=NULL;
	dxs rear=P;
	while(t2){
		Attach((t1->xishu*t2->xishu),(t1->zhishu+t2->zhishu),&rear);
		t2=t2->next;
		printf("ok\n");
	}
	t1=t1->next;
	while(t1){
		t2=p2;rear=P;
		while(t2){
			rear=P;
			int xishu=t1->xishu*t2->xishu;
			int zhishu=t1->zhishu+t2->zhishu;
			while(rear->next && rear->next->zhishu>zhishu){
				rear=rear->next;
				printf("ok this is oldandold\n");
			}	
			if (rear->next && rear->next->zhishu==zhishu){
				if((rear->next->xishu+xishu)!=0){
					rear->next->xishu+=xishu;
					printf("ok this is old \n");
				}else{
					dxs temp=rear->next;
					rear->next=temp->next;
					free(temp);
					printf("ok this is zero\n");
				}		
			}
			else if (rear->next){
				dxs insert=(dxs)malloc(sizeof(dxs));
				insert->next=rear->next;
				rear->next=insert;
				printf("ok this is new\n");
				insert->xishu=xishu;
				insert->zhishu=zhishu;
			}
			else if (zhishu>=0 && rear->next==NULL){
				Attach(xishu,zhishu,&rear);printf("ok this is last\n");
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	dxs t=P;P=P->next;free(t);
	return P;
}
void main(){
	dxs P1=readonly();
	dxs P2=readonly();
	dxs P3=Add(P1,P2);
	dxs P4=Mulit(P1,P2);
	Print(P1);
	Print(P2);
	Print(P3);
	Print(P4);
}
