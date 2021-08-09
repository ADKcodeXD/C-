//˳����� 
#include <stdio.h>
#include <stdlib.h>
#define anytype int
#define MAXSIZE 50
//˳���Ķ��� 
typedef struct L *List;
struct L{
    anytype *DATA;
    int Last;
};
//������˳���
List null_list(){
    List Pointer;
    Pointer=(List)malloc(sizeof(struct L));
    Pointer->DATA=malloc(sizeof(int)*MAXSIZE);
    Pointer->Last=-1;
    return Pointer;
}
//���س��� 
int List_Length(List Pointer){
    return (Pointer->Last++);    
}
//���Ԫ��
int List_Add(anytype X,List Pointer){
    
    if(Pointer->Last >= MAXSIZE-1){
        return 0;
    }
    else {
        Pointer->Last++;
        Pointer->DATA[Pointer->Last]=X;
        return 1;
    }
} 
//����Ԫ��
void List_Find(anytype X,List Pointer){
     int i; 
    while(i<=Pointer->Last && Pointer->DATA[i]!=X){
        i++;
    }
    if (i>Pointer->Last){
        printf("No found!\n");
        return ;
    }
    printf("Found!\n");
 }
 //����Ԫ��
 List List_Insert(anytype X,List Pointer,int i){
     if (Pointer->Last >=MAXSIZE-1 ){
         return 0;
     }
     if (i<0){
         printf("The given position is invalid!\n");
         return 0;
     }
     if(i>Pointer->Last){
         printf("The given position is invalid!\n");
         return 0;
     }
     int j=++Pointer->Last;
     while(j>=i-1){
         Pointer->DATA[j+1]=Pointer->DATA[j];
         j--;
     }
     Pointer->DATA[i-1]=X;
     return Pointer;
 }
 //ɾ��Ԫ��
List List_Delete(anytype X,List Pointer){
     int i;
     for (i=0;i<=Pointer->Last;i++){
         if (Pointer->DATA[i]==X){
             Pointer->DATA[i]=0;
             for(;i<=Pointer->Last;i++){
                 Pointer->DATA[i]=Pointer->DATA[i+1];
             }
         Pointer->Last--;
         return Pointer;
         }
     }
     return Pointer;
 }
 //��ӡ���Ա�
 void printa(List Pointer){
     int i;
     for(i=0;i<=Pointer->Last;i++){
         printf("%d ",Pointer->DATA[i]);
     }
 } 
 void main(){
    int a,i;
    scanf("%d",&a);
    if(a>MAXSIZE){
        printf("The List counld not store all elements.\n");
        exit(0);
    }
    List p=null_list();
    for(i=0;i<a;i++){
        anytype X;
        scanf("%d",&X);
        List_Add(X,p);
    }
    printa(p);printf("\n");
    List_Find(30,p);
    List_Find(67,p);
    List_Insert(12,p,5);
    printa(p);printf("\n");
    List_Insert(18,p,10);
    printa(p);printf("\n");
    List_Delete(10,p);
    printa(p);printf("\n");
}
