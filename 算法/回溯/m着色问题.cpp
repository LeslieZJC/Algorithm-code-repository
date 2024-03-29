#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
int graph[maxn][maxn],x[maxn],n,m,l,total=0;
bool judge(int k){
	for(int i=1;i<=n;i++){
		if(graph[k][i]==1&&x[k]==x[i])
			return false;
	}
	return true;
}
void backtrack(int t){
	if(t>n){
		total++;
		return;
	}
	else{
		for(int i=1;i<=m;i++){
			x[t]=i;
			if(judge(t))
				backtrack(t+1);
			x[t]=0;
		}
	}
}
int main(){
	cin>>n>>l>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			graph[i][j]=0;
	for(int i=1;i<=l;i++){
		int t1,t2;
		cin>>t1>>t2;
		graph[t1][t2]=1;
		graph[t2][t1]=1;
	}
	backtrack(1);
	cout<<total;
	return 0;
} 
