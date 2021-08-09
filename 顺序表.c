//顺序表创建 
#include <stdio.h>
#define anytype int
#define MAXSIZE 10
//顺序表的定义 
typedef struct L *List;
struct L{
	anytype DATA[MAXSIZE];
	int Last;
};
//创建空顺序表
List null_list(){
	List Pointer;
	Pointer=(List)malloc(sizeof(struct L));
	Pointer->Last=-1;
	return Pointer;
}
//返回长度 
int List_Length(List Pointer){
	return (Pointer->Last++);	
}
//添加元素
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
//查找元素
 int List_Find(anytype X,List Pointer){
 	int i; 
	while(i<=Pointer->Last && Pointer->DATA[i]!=X){
		i++;
	}
	if (i>Pointer->Last){
		return -1;
	}
	return i+1;
 }
 //插入元素
 int List_Insert(anytype X,List Pointer,int i){
 	if (Pointer->Last >=MAXSIZE-1 ){
 		return 0;
 	}
 	int j=Pointer->Last;
 	while(j>=i){
 		Pointer->DATA[j+1]=Pointer->DATA[j];
 		j--;
 	}
 	Pointer->DATA[i]=X;
 	Pointer->Last++;
 	return 1;
 }
 //删除元素
 int List_Delete(anytype X,List Pointer){
 	int i;
 	for (i=0;i<=Pointer->Last;i++){
 		if (Pointer->DATA[i]==X){
 			Pointer->DATA[i]=0;
 			for(;i<=Pointer->Last;i++){
 				Pointer->DATA[i]=Pointer->DATA[i+1];
 			}
 		Pointer->Last--;
 		return 1;
 		}
 	}
 	return 0;
 }
 int main(){
 	int i;
 	List a=null_list();
 	for(i=0;i<=6;i++)
	 List_Add(i,a);
	List_Insert(8,a,3);
	for(i=0;i<10;i++)
		printf("%d ",a->DATA[i]);
		printf("\n");
	List_Delete(5,a);
	for(i=0;i<10;i++)
		printf("%d ",a->DATA[i]);
		printf("\n");
	printf("%d",List_Find(4,a));
	printf("\n");
	
 	return 0;
 }
