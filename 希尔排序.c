#include<stdio.h>
#include<stdlib.h>
void shell_sort(int *data,int N){
	int D,p,i;
	for(D=N/2;D>0;D/=2){
		for(p=D;p<N;p++){
			int temp=data[p];
			for(i=p; i>=D && data[i-D]>temp;i-=D)
				data[i]=data[i-D];
			data[i]=temp;
		}
	}
}
void main(){
	int a;int i;
	scanf("%d",&a);
	int *data;
	data=malloc(sizeof(int)*a);
	for(i=0;i<a;i++){
		if(i==a-1){
			scanf("%d",&data[i]);
		}else
		scanf("%d ",&data[i]);
	}
	shell_sort(data,a);
	for(i=0;i<a;i++){
		printf("%d ",data[i]);
	}
} 
