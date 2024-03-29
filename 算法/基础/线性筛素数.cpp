#include <iostream>
#include <stdlib.h>
#include <cstring>
#define MAX 10010
int check[MAX];
int prime[MAX];
int total=0;
void judge(int max){
	int i,j;
	memset(check, 0, sizeof(check));
	for(i=2;i<=max;i++){
		if(!check[i])
			prime[total++]=i;
		for (int j=0;j<total;++j){
			if(i*prime[j]>max)
				break;
			check[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;//判断是否会重复筛选，依次向后筛 
		} 
	}
}
int main(){
	int m,n,k;
	scanf("%d%d",&m,&n);	
	judge(m);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		printf("%d\n",prime[k-1]);
	}
} 
