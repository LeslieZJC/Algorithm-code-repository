#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
char map1[maxn][maxn];int num=0;
int n,m;
int a[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int judge(int x,int y){
	int c=0;
	if(map1[x][y]=='#')c++;
	if(map1[x+1][y]=='#')c++;
	if(map1[x][y+1]=='#')c++;
	if(map1[x+1][y+1]=='#')c++;
	if(c==3)return 0;
	return 1;
}
void dfs(int x,int y){
	map1[x][y]='.';
	for(int i=0;i<=3;i++){
		int xx=x+a[i][0];
		int yy=y+a[i][1];
		if(xx<1||xx>n||yy<1||yy>m)
			continue;
		if(map1[xx][yy]=='#')
			dfs(xx,yy);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>map1[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i<n&&j<m&&judge(i,j)==0){
				printf("Bad placement.");
				return 0;
			}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map1[i][j]=='#'){
				num++;
				dfs(i,j);	
			}
	printf("There are %d ships.",num);
	return 0;
} 

