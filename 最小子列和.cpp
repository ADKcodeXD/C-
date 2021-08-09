#include<stdio.h>
int maxsub(int list[],int n){
    int maxsum=0;
    
    for(int i=0;i<n;i++){
		int thissum; 
        thissum+=list[i];
        if(thissum>maxsum){
            maxsum=thissum;
        }else if(thissum<0){
            thissum=0;
        }
    }
    return maxsum;
}

int main(){
    int n;
    scanf("%d",&n);
    const int MAXSIZE=n;
    int list[MAXSIZE];
    for(int i=0;i<MAXSIZE;i++){
        scanf("%d",&list[i]);
    }
    printf("%d",maxsub(list,n));
}
