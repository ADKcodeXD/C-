#include <stdio.h>
#include <stdlib.h>
typedef struct lianbiao{
	int number;
	struct lianbiao *next;
}lian;
int main()
{
	lian *head=NULL;
	int num;
	do{
		scanf("%d",&num);
		if(num!=-1){
			lian *p=(lian*)malloc(sizeof(lian));
			p->number=num;
			p->next=NULL;
			lian *last=head;
			if(last){
				while(last->next){
				last=last->next;
			  }
				last->next=p;
			} else{
				head=p;
			}
		}
	}while(num!=-1);
	return 0;
}
