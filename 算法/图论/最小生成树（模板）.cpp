#include <bits/stdc++.h>
#define inf 0x7fffffff
#define maxn 1001
using namespace std;
int graph[maxn][maxn],lowcost[maxn],n,m,mst[maxn],sum;//lowcost ��¼����ͨͼ��̵ı� 
void kruskal(){
		
} //��ô�ж��Ƿ���ͨ��n-1���߲��ܹ�����ͨͼ����һ��������·��ֻҪ��ѡ�ߵ�ʱ���ж��ǲ��ǻ�·������ 
/*
	����ķ�ʽ�����ǲ��ǹ���ͬһ����� 
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
				sign=j;//ѡ�˵�j���㵽��ͨͼ�ı� 
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
	}//ѭ��n-1�Σ�ÿ�ζ�����lowcost��ֵ 
}//��Ȧ��
//��Ȧ�� 
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

