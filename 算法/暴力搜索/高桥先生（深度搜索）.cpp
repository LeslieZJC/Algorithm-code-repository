#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define maxn 505
using namespace std;
int a[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[maxn][maxn];
int n,m,flag,s1,s2,book[maxn][maxn];
void dfs(int x,int y){
	if(s[x][y]=='g'){
		flag=1;
		return;
	}
	for(int i=0;i<4;i++){
		int xx=x+a[i][0];
		int yy=y+a[i][1];
		if(xx<1||xx>n||yy<1||yy>m||s[xx][yy]=='#'||book[xx][yy]!=0)
			continue;
		book[xx][yy]=1;
		dfs(xx,yy);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='s'){
				s1=i;
				s2=j;
			}
		}
	}
	dfs(s1,s2);
	if(flag==1)
		printf("Yes");
	else
		printf("No");
	return 0;
}
