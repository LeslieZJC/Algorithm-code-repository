#include <bits/stdc++.h>
#define maxn 41
using namespace std;
typedef long long ll;
ll dp[maxn][maxn],b1,b2,m1,m2;
ll map1[maxn][maxn];
int a[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int main(){
	cin>>m1>>m2>>b1>>b2;
	m1++;m2++;b1++;b2++; 
	map1[b1][b2]=1;
	for(int i=0;i<8;i++){
		int xx=b1+a[i][0];
		int yy=b2+a[i][1];
		map1[xx][yy]=1;
	}		
	dp[1][1]=1;
	for(int i=2;i<=m2;i++){
		if(map1[1][i]==1)
			continue;
		dp[1][i]=dp[1][i-1];
	}
	for(int i=2;i<=m1;i++){
		for(int j=1;j<=m2;j++){
			if(map1[i][j]==1)
				continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	printf("%lld",dp[m1][m2]);
	return 0;
}
//			if(map1[i-1][j-1]==1&&map1[i][j-1]==1&&map1[i-1][j]==0)
//				dp[i][j]=dp[i-1][j]; 
//			else if(map1[i-1][j-1]==1&&map1[i][j-1]==0&&map1[i-1][j]==1)
//				dp[i][j]=dp[i][j-1];
//			else if(map1[i-1][j-1]==1&&map1[i][j-1]==0&&map1[i-1][j]==0)
//				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//			else if(map1[i-1][j-1]==0&&map1[i][j-1]==0&&map1[i-1][j]==0)
//				dp[i][j]=max(dp[i-1][j]+1,dp[i][j-1]+1);
