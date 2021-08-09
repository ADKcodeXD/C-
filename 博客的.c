#include <stdio.h>
#include <malloc.h>
#define Maxsize 100
typedef int QElemType;
typedef struct Lnode{
    int data;
    struct Lnode *next;
}Node,*SqQueue;
int count=0;
SqQueue QueueInit(SqQueue rear)
{
    rear=(SqQueue)malloc(sizeof(Node));
    if(!rear)
        printf("error");
    else{
        rear->next=rear;
    }
    return rear;
}

SqQueue InsertQueue(SqQueue rear,QElemType e)
{
    SqQueue p;
    p=(SqQueue)malloc(sizeof(Node));
    p->data=e;
    p->next=rear->next;
    rear->next=p;
    rear=p;
    count++;
    return rear;
}

SqQueue OutQueue(SqQueue rear)
{
    int e;
    SqQueue p;
    if(rear==rear->next)
        printf("error");
    else{
        p=rear->next->next;
        e=p->data;
        rear->next->next=p->next;
        if(rear==p)
        {
            rear=rear->next;
        }
        free(p);
    }
    printf("%d",e);
    count--;
    return rear;
}

int main()
{
    SqQueue rear,p,q;
    int e,i;
    rear=QueueInit(rear);
    for(i=0;i<4;i++)
    {
        rear=InsertQueue(rear,i+1);
    }
    p=rear->next->next;
    for(i=0;i<4;i++)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    rear=OutQueue(rear);
    printf("\n");
    q=rear->next->next;
    for(i=0;i<3;i++)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    return 0;
}
