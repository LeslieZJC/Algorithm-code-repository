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
    while(p>0)//������
    {
        if(p%2!=0)
            ans=ans*b%k;//���pΪ�������˵�ans����ȥ��Ȼ��ȡģ
        b=b*b%k;//ÿ�����㶼ȡģ
        p=p>>1;    //��λ�����2�����ܻ��һ��
    }
    ans %= k;//����ǰ�Ĵ����ˡ�������ͻȻ�����д��и�֪���������ϸһ������p = 0ʱû��ȡģ��������仰�Ϳ�����
    printf("%d^%d mod %d=%d",a,c,k,ans);//���
    return 0;
}
