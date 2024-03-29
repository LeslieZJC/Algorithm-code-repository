#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	int all,num;
	int time[100],value[100],dp[100][1000];
	scanf("%d%d",&all,&num);
	for(int i=1;i<=num;i++){
		scanf("%d",&time[i]);
		scanf("%d",&value[i]);
	}
	for(int i=1;i<=num;i++)
		for(int j=0;j<=all;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=time[i])
				dp[i][j]=max(dp[i-1][j],dp[i][j-time[i]]+value[i]);
		}
	printf("%d",dp[num][all]);
	return 0; 
}

