//#include <iostream>
//typedef long long ll;
//ll mod;
//int qpow(ll a,ll n){
//	if(n==0)
//		return 1;
//	else if(n%2==1)
//		return qpow(a,n-1)*a%mod;
//	else{
//		int temp=qpow(a,n/2)%mod;
//		return temp*temp%mod;
//	} 
//}
//int main(){
//	ll a,n;
//	scanf("%d%d%d",&a,&n,&mod);
//	printf("%d^%d mod %d=%d",a,n,mod,qpow(a,n));
//}
#include<bits/stdc++.h>
using namespace std;
long long b,a,p,k,ans=1,c;
int main()
{
    scanf("%d%d%d",&b,&p,&k);
    a=b;c=p;
    while(p>0)//快速幂
    {
        if(p%2!=0)
            ans=ans*b%k;//如果p为单数，乘到ans里面去，然后取模
        b=b*b%k;//每次运算都取模
        p=p>>1;    //用位运算除2，可能会快一点
    }
    ans %= k;//多年前的代码了……今天突然发现有大佬告知代码错误，仔细一看是在p = 0时没有取模，加上这句话就可以了
    printf("%d^%d mod %d=%d",a,c,k,ans);//输出
    return 0;
}
