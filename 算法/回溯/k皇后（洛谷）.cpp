#include <bits/stdc++.h>
#define maxn 10001
using namespace std;
int n,m,K,sign[20001],total,sum,x[501],y[501];
int h[20001];
void khh(){
	for(int i=1;i<=n;i++){
		if(h[i]==1)
			continue;
		memset(sign,0,sizeof(sign));
		for(int j=1;j<=K;j++){
			sign[y[j]]=1;//等于1是被攻击到的			
			if(x[j]<i){
				int yy=x[j]-i;
				if(y[j]-yy>=1)
					sign[y[j]-yy]=1;
				if(y[j]+yy<=m)
					sign[y[j]+yy]=1;
			}
			else{
				int yy=i-x[j];
				if(y[j]-yy>=1)
					sign[y[j]-yy]=1;
				if(y[j]+yy<=m)
					sign[y[j]+yy]=1;
			}
		}
		for(int j=1;j<=m;j++)
			if(sign[j]==1)
				total++;
	}
}
int main(){
	cin>>n>>m>>K;
	for(int i=1;i<=K;i++){
		cin>>x[i]>>y[i];
		h[x[i]]=1;//true代表有皇后 
	}
	khh();
	cout<<total;
	return 0;
}
