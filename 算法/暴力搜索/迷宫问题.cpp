//#include <iostream>
//#include <stdio.h>
//#include <cstring>
//#include <algorithm>
//#define MAX 100
//using namespace std;
//int N,M,T,SX,SY,FX,FY,map[MAX][MAX],sign[MAX][MAX],MIN=9999;
//int a[4][2]={{0,1}, //向右走一步
//			{1,0},//向下走一步
//			{0,-1},//向左走一步
//			{-1,0}};//向上走一步
//void dfs(int x,int y,int step){
//	if(x==FX&&y==FY){
//		if(step<MIN)
//			MIN=step;
//		return;
//	}
//	for(int i=0;i<=3;i++){
//		int xx=x+a[i][0];
//		int yy=y+a[i][1];
//		if(xx<1||xx>N||yy<1||yy>M)
//			continue;
//		if(map[xx][yy]==0&&sign[xx][yy]==0){
//			sign[xx][yy]=1;
//			dfs(xx,yy,step+1);
//			sign[xx][yy]=0;
//		}
//	}
////	return;
//}
//int main(){
//	scanf("%d%d%d",&N,&M,&T);
//	scanf("%d%d%d%d",&SX,&SY,&FX,&FY);
//	for(int i=1;i<=N;i++)
//		for(int j=1;j<=M;j++){
//			map[i][j]=0;
//			sign[i][j]=0;
//		}			
//	for(int i=0;i<T;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		map[x][y]=1;
//	}
//	sign[SX][SY]=1;
//	dfs(SX,SY,0);
//	printf("%d",MIN);
//	return 0;
//} //最短的步数 
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAX 100
using namespace std;
int N,M,T,SX,SY,FX,FY,map[MAX][MAX],sign[MAX][MAX],total=0; 
int a[4][2]={{0,1}, //向右走一步
			{1,0},//向下走一步
			{0,-1},//向左走一步
			{-1,0}};//向上走一步
void dfs(int x,int y){
	if(x==FX&&y==FY){
		total++;
		return;
	}
	for(int i=0;i<=3;i++){
		int xx=x+a[i][0];
		int yy=y+a[i][1];
		if(xx<1||xx>N||yy<1||yy>M)
			continue;
		if(map[xx][yy]==0&&sign[xx][yy]==0){
			sign[xx][yy]=1;
			dfs(xx,yy);
			sign[xx][yy]=0;
		}
	}
//	return;
}
int main(){
	scanf("%d%d%d",&N,&M,&T);
	scanf("%d%d%d%d",&SX,&SY,&FX,&FY);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			map[i][j]=0;
			sign[i][j]=0;
		}			
	for(int i=0;i<T;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=1;
	}
	sign[SX][SY]=1;
	dfs(SX,SY);
	printf("%d",total);
	return 0;
} //总的路线个数 
