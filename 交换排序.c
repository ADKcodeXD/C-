#include <stdio.h>
void sort(char *name,int n)
{
	int i,j,temp=0,index=0;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(name[j]<name[index]){
				index=j;
			}	
		}
		if(index!=i){
			temp=name[i];
			name[i]=name[index];
			name[index]=temp;
		}
	}

}
int main()
{
	char a[10];
	scanf("%s",a);
	char *p=&a;
	sort(p,10);
	printf("%s",a);
}

