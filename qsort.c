#include<stdio.h>
int cnt=0;
void qsort(int start,int end,int a[]){
	cnt++;
	int piviot=a[start];
	int i=start+1;
	int j=end;
	int k=10;
	int q=0;
	while(i!=j){
		while(a[j]>piviot && i<j){
			j--;
		}
		while(a[i]<piviot && i<j){
			i++;
		}
		if(i<j){
			int t;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[start]=a[i];
	a[i]=piviot;
	printf("这是第%d次的输出:",cnt);
	for(q=0;q<k;q++)
		printf("%d ",a[q]);
	printf("\n");
	qsort(start,i-1,a);
	qsort(i+1,end,a);
}
void main(){
	int a[10];
	int i;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	qsort(0,9,a);
} 
