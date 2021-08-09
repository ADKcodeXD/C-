#include<stdio.h>
#include<stdlib.h>
void quick_sort(int a[], int left, int right)  
{  
    if (left<right) 
    {   
    	//第一个数字当哨兵
        int i=left, j=right, pivot=a[left];
        while (i<j)
        {
            while(i<j && a[j]>=pivot)
                j--;
            if(i<j)
            //找到第一个小于哨兵的
                a[i++]=a[j];
            while(i<j && a[i]<pivot)
                i++;
            if(i < j)
                a[j--]=a[i];
        }
        a[i]=pivot;
        quick_sort(a,left,i-1); 
        quick_sort(a,i+1,right);  
    }  
} 
int Binarysearch(int a[],int x,int total){
	int s=0;int b=total;
	while(s<b){
		int mid=((s+b)/2);
		if (a[mid]==x){
			printf("%d ",mid+1);
			return 1;
		}
		if(a[mid]>x){
			b=mid;
		}else if(a[mid]<x){
			s=mid;
		}
		else{
			printf("未找到！\n");
			return 0;
		}
	}
}
void main(){
	int n;int i;int c,d;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		if(i==n-1)
			scanf("%d",&a[i]);
		else
			scanf("%d ",&a[i]);
	}
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	scanf("%d",&c);
	Binarysearch(a,c,n-1);
//	printf("\n");
//	scanf("%d",&d);
//	Binarysearch(a,d,n-1);
//	printf("\n");
//	printf("\n");
//	scanf("%d,%d",&c,&d);
//	printf("%d ",Binarysearch(a,c,n-1));
//	printf("%d",Binarysearch(a,d,n-1));
}
