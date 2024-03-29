#include <bits/stdc++.h>
#define maxn 1001
typedef long long ll;
using namespace std;
int T,n,h,flag1[100001],flag2[100001],len1=0,len2=0;
int fa[maxn],rank1[maxn],flag=0;
ll x[100001],y[100001],z[100001],r;
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
	if(rank1[x]<=rank1[y])
		fa[x]=y;
	else
		fa[y]=x;
	if(rank1[x]==rank1[y]&&x!=y)
		rank1[y]++;
}
long long dis(long long x,long long y,long long z,long long x1,long long y1,long long z1){
    return (x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%lld",&n,&h,&r);
		init(n);
		flag=0;len1=0;len2=0;
		memset(flag1,0,sizeof(flag1));
		memset(flag2,0,sizeof(flag2));
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
			if(z[i]<=r)
				flag1[len1++]=i;
			if(z[i]>=h-r)
				flag2[len2++]=i;
			for (int j=1;j<=i;j++){
            	if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])>4*r*r) continue; 
                if(dis(x[i],y[i],z[i],x[j],y[j],z[j])<=4*r*r)
					merge(i,j);
            }
		}
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				if(find(flag1[i])==find(flag2[j])){
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
} 
