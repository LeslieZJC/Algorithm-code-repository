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
//	dfs(x,y+1);//ȡ���߲�ȡ 
//	if(book[x][y]==0){
//		ans+=map1[x][y];
//		for(int fx=0;fx<8;++fx){ //�����Χ���� 
//			++book[x+a[fx][0]][y+a[fx][1]];
//		}
//		dfs(x,y+1);
//		for(int fx=0;fx<8;++fx){ //�����Χ���� 
//			++book[x+a[fx][0]][y+a[fx][1]];
//		}
//		ans-=map1[x][y];//���� 
//	}
//}
//int main(){
//	cin>>num;
//	while(num--){
//		memset(map1,0,sizeof(map1));
//		memset(book,0,sizeof(book));//����ÿ������ǰ��Ҫ��ʼ������ 
//		cin>>n>>m;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cin>>map1[i][j];
//			}
//		}
//		mx=0;ans=0;
//		dfs(1,1);//�ӵ�(1,1)��ʼ���� 
//		printf("%d\n",mx);//����� 
//	}
//	return 0;
//}
#include<bits/stdc++.h>//����ͷ�ļ� 
#define maxn 1001
using namespace std;
int d[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};//��������������������ʱ�ķ��� 
int t,n,m,map1[maxn][maxn],book[maxn][maxn],ans,mx;
void dfs(int x,int y){//������������ʾ������(x,y) 
	if(y==m+1){//��y���߽�ʱ��������һ�� 
		dfs(x+1,1);
		return;
	}
	if(x==n+1){//��x���߽�ʱ������������ˢ�����ֵ 
		mx=max(ans,mx);
		return;
	}
	
	dfs(x,y+1);// ��ȡ��������� 
	
	if(book[x][y]==0){ //ȡ������������豣֤������Χû��ȡ����������mark[i][j]==0��
		ans+=map1[x][y];
		for(int fx=0;fx<8;++fx){ //�����Χ���� 
			++book[x+d[fx][0]][y+d[fx][1]];
		}
		dfs(x,y+1);
		for(int fx=0;fx<8;++fx){ //���� 
			--book[x+d[fx][0]][y+d[fx][1]];
		}
		ans-=map1[x][y];
	}
	
}
int main(){
	cin>>t; 
	while(t--){
		memset(map1,0,sizeof(map1));
		memset(book,0,sizeof(book));//����ÿ������ǰ��Ҫ��ʼ������ 
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>map1[i][j];
			}
		}
		mx=0;
		dfs(1,1);//�ӵ�(1,1)��ʼ���� 
		printf("%d\n",mx);//����� 
	}
	return 0;
}
