#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
typedef struct pt{
	int x,y;
}pt;
queue<struct pt>q;
int book[maxn][maxn],map1[maxn][maxn],n,m,num=0;
int a[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void bfs(int x,int y){
	pt p;
	p.x=x;p.y=y;
	book[x][y]=1;
	q.push(p);
	while(!q.empty()){
		pt t=q.front();
		for(int i=0;i<4;i++){
			pt k=t;//为什么要加个临时变量 
			k.x+=a[i][0];
			k.y+=a[i][1];
			if(k.x<1||k.x>n||k.y<1||k.y>m||map1[k.x][k.y]==0||book[k.x][k.y]!=0)
				continue;
			book[k.x][k.y]=1;
			q.push(k);
		}
		q.pop();
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&map1[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map1[i][j]!=0&&book[i][j]==0){
				bfs(i,j);
				num++;
			}
		}
	}
	printf("%d",num);
	return 0;
}
