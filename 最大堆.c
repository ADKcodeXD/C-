#include<stdio.h>
#include<stdlib.h>
#define maxsize 50
#define Maxdata 1000
typedef struct heapstruct *heap;
struct heapstruct{
	int size;
	int *data;
	int max;
};
heap create(int maxsize1){
	heap h=(heap)malloc(sizeof(struct heapstruct));
	h->data=malloc(sizeof(int)*(maxsize+1));
	h->size=0;
	h->max=maxsize1;
	h->data[0]=Maxdata;
	return h;
}
int isFull(heap h){
	if (h->size>=maxsize){
		return 1;
	}else
	return 0;
}
void insert(heap h,int item){
	int i;
	if (isFull(h)){
		printf("最大堆已满！");
		return;
	}
		i=h->size+1;
		h->size+=1;
		for(;h->data[i]<item;i/=2){
			h->data[i]=h->data[i/2];
		}
		h->data[i]=item;
}
void input(heap h,int item){
	int i;
	if (isFull(h)){
		printf("最大堆已满！");
		return;
	}
	i=++h->size;
	h->data[i]=item;
}
int deletemax(heap h){
	int parent,child;
	int maxtemp,temp;
	if (isFull(h)){
		printf("最大堆已满！");
		return;
	}
	maxtemp=h->data[1];
	temp=h->data[h->size++];
	for(parent=1;parent*2<=h->size;parent=child){
		child=parent*2;
		if((child!=h->size)&&(h->data[child]<h->data[child+1])){
			child++;
		}
		if(temp>=h->data[child])break;
		else
			h->data[parent]=h->data[child];
	}
	h->data[parent]=temp;
	return maxtemp;
}
void print(heap h){
	int i;
	for(i=1;i<=h->size;i++){
		printf("%d ",h->data[i]);
	}
}
void init(heap h){
	//有bug 
	int i=0;
	int temp=0;
	i=h->size/2;
	for(;i>=1;i--){
		temp=h->data[i];
		int son=i*2;
		while(son<=h->size){
			if(son<h->size&&h->data[son]<h->data[son+1])
				son++;
			if(temp>h->data[son]){
				break;
			}else{
				h->data[son/2]=h->data[son];
				son*=2;
			}
		}
		h->data[son/2]=temp;
	}
}
void main(){
	heap h=create(maxsize);
	int o,q,data;
	scanf("%d",&o);
	for (q=0;q<o;q++){
		scanf("%d",&data);
		input(h,data);
	}
	print(h);
	printf("\n");
	init(h);
	print(h);
}
