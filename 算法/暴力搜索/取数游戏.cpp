//#include <bits/stdc++.h>
//#define maxn 1001
//using namespace std;
//int a[8][2]={1,0,-1,0,0,1,0,-1,1,1,-1,1,1,-1,-1,-1};
//int map1[maxn][maxn],book[maxn][maxn],mx=0,ans,num,n,m;
//void dfs(int x,int y){
//	
//	if(y==m+1){
//		dfs(x+1,1);
//		return;
//	} if(x==n+1){
//		mx=max(mx,ans);
//		return;
//	}
//	dfs(x,y+1);//取或者不取 
//	if(book[x][y]==0){
//		ans+=map1[x][y];
//		for(int fx=0;fx<8;++fx){ //标记周围的数 
//			++book[x+a[fx][0]][y+a[fx][1]];
//		}
//		dfs(x,y+1);
//		for(int fx=0;fx<8;++fx){ //标记周围的数 
//			++book[x+a[fx][0]][y+a[fx][1]];
//		}
//		ans-=map1[x][y];//回溯 
//	}
//}
//int main(){
//	cin>>num;
//	while(num--){
//		memset(map1,0,sizeof(map1));
//		memset(book,0,sizeof(book));//在做每个数据前都要初始化数组 
//		cin>>n>>m;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cin>>map1[i][j];
//			}
//		}
//		mx=0;ans=0;
//		dfs(1,1);//从点(1,1)开始搜索 
//		printf("%d\n",mx);//输出答案 
//	}
//	return 0;
//}
#include<bits/stdc++.h>//万能头文件 
#define maxn 1001
using namespace std;
int d[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};//方向数组用来控制搜索时的方向 
int t,n,m,map1[maxn][maxn],book[maxn][maxn],ans,mx;
void dfs(int x,int y){//搜索函数，表示搜索点(x,y) 
	if(y==m+1){//当y到边界时，搜索下一行 
		dfs(x+1,1);
		return;
	}
	if(x==n+1){//当x到边界时，搜索结束，刷新最大值 
		mx=max(ans,mx);
		return;
	}
	
	dfs(x,y+1);// 不取此数的情况 
	
	if(book[x][y]==0){ //取此数的情况（需保证此数周围没有取其他数，即mark[i][j]==0）
		ans+=map1[x][y];
		for(int fx=0;fx<8;++fx){ //标记周围的数 
			++book[x+d[fx][0]][y+d[fx][1]];
		}
		dfs(x,y+1);
		for(int fx=0;fx<8;++fx){ //回溯 
			--book[x+d[fx][0]][y+d[fx][1]];
		}
		ans-=map1[x][y];
	}
	
}
int main(){
	cin>>t; 
	while(t--){
		memset(map1,0,sizeof(map1));
		memset(book,0,sizeof(book));//在做每个数据前都要初始化数组 
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>map1[i][j];
			}
		}
		mx=0;
		dfs(1,1);//从点(1,1)开始搜索 
		printf("%d\n",mx);//输出答案 
	}
	return 0;
}
