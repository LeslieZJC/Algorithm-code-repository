#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
	ll win[1010],lose[1010],ys[1010],dp[1010],n,x;
	scanf("%lld%lld",&n,&x);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&lose[i]);
		scanf("%lld",&win[i]);
		scanf("%lld",&ys[i]);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=x;j>=0;j--){
			if(j>=ys[i])
				dp[j]=max(dp[j]+lose[i],dp[j-ys[i]]+win[i]);
			else
				dp[j]=dp[j]+lose[i];
		}
	}
	printf("%lld",5*dp[x]);
	return 0;
}
