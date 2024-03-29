#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
int fa[maxn],n,m,p,t1,t2,rank1[maxn];
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		rank1[i]=i;
	}
}
int find(int x){
	if(fa[x]==x)
		return x;
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}	
} 
void merge(int i,int j){
	int x=find(i),y=find(j);
    if (rank1[x]<=rank1[y])
        fa[x]=y;
    else
        fa[y]=x;
    if (rank1[x]==rank1[y]&&x!=y)
        rank1[y]++;
}
int main(){
	cin>>n>>m>>p;
	init(n);
	for(int i=0;i<m;i++){
		cin>>t1>>t2;
		merge(t1,t2);
	}
	for(int i=0;i<p;i++){
		cin>>t1>>t2;
		if(find(t1)==find(t2))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
