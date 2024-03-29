#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 300
using namespace std;
int g[MAX][MAX];
int dp[MAX];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			cin>>g[i][j];
	memset(dp,50000,sizeof(dp));
	dp[1]=0;
	for(int j=2;j<=n;j++){
		for(int i=1;i<j;i++){
			dp[j]=min(dp[j],dp[i]+g[i-1][j-1]);//²»Í£¸üÐÂdp[j] 
		}
	}	
	printf("%d",dp[n]);
}
