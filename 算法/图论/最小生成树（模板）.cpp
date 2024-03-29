#include <bits/stdc++.h>
#define inf 0x7fffffff
#define maxn 1001
using namespace std;
int graph[maxn][maxn],lowcost[maxn],n,m,mst[maxn],sum;//lowcost 记录到连通图最短的边 
void kruskal(){
		
} //怎么判断是否连通，n-1条边不能构成连通图，那一定包含回路，只要在选边的时候判断是不是回路就行了 
/*
	分组的方式，看是不是共用同一个编号 
*/
void prim(){
	for(int i=2;i<=n;i++){
		lowcost[i]=graph[1][i];
		mst[i]=1;
	}
	for(int i=2;i<=n;i++){
		int minid=inf,sign=0;
		for(int j=2;j<=n;j++){
			if(lowcost[j]<minid&&lowcost[j]!=0){
				minid=lowcost[j];
				sign=j;//选了第j个点到连通图的边 
			}
		} 
		sum+=minid;
		lowcost[sign]=0;
//		cout<<"V"<<mst[sign]<<"-V"<<sign<<"="<<minid<<endl;
		for(int j=2;j<=n;j++){
			if(graph[sign][j]<lowcost[j]){
				lowcost[j]=graph[sign][j];
				mst[j]=sign;
			}
		}
	}//循环n-1次，每次都更新lowcost的值 
}//避圈法
//破圈法 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			graph[i][j]=inf;
	for(int i=1;i<=m;i++){
		int t1,t2,t3; 
		cin>>t1>>t2>>t3;
		if(t3<graph[t1][t2]){
			graph[t1][t2]=t3;
			graph[t2][t1]=t3;
		}
	}
	prim();
	cout<<sum;
	return 0;
} 

