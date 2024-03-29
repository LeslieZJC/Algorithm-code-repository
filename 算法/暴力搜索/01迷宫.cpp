#include <bits/stdc++.h>
#define maxn 10001
using namespace std;
int n,m,map1[maxn][maxn],sx,sy,total=1,book[maxn][maxn],ans[100002];
int a[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y,int t,int j){
	for(int i=0;i<4;i++){
		int xx=x+a[i][0];
		int yy=y+a[i][1];
		if(xx<1||xx>n||yy<1||yy>n||map1[xx][yy]==t||book[xx][yy]!=0)
			continue;
		total++;
		book[xx][yy]=j;
		dfs(xx,yy,map1[xx][yy],j);	
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&map1[i][j]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&sx,&sy);
		if(book[sx][sy]==0){
			book[sx][sy]=i;
			dfs(sx,sy,map1[sx][sy],i);
			ans[i]=total;
			total=1;
		}
		else{
			ans[i]=ans[book[sx][sy]];
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
