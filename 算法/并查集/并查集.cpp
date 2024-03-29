#include <iostream>
#include <stdlib.h>
#define MAX 10010 
int fa[MAX];
int rank[MAX];//记录每个根节点对应的树的深度
void init(int n){
	for(int i=0;i<n;i++){
		fa[i]=i;
		rank[i]=1;
	}
}
int find(int x){
	if(fa[x]==x)
		return x;
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}//顺变路径压缩 
void merge(int i,int j){
	int x = find(i), y = find(j);
    if (rank[x]<=rank[y])
        fa[x]=y;
    else
        fa[y]=x;
    if (rank[x]==rank[y]&&x!=y)
        rank[y]++;
}
int main(){
	int n,m,i=0,x,y,z;
	scanf("%d%d",&n,&m);
	init(n);
	while(i<m){
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
			merge(y,z);
		if(x==2){
			if(find(y)==find(z))
				printf("Y\n");
			else
				printf("N\n"); 
		}
		i++;
	}
	return 0;
}
