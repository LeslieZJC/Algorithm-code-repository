#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define mod 2123704401301339ll;
using namespace std;
typedef unsigned long long ll;
ll hash[10010];
ll base=293;
ll p=832394;
ll getHash(char s[]){
	ll ans=0;
	for(int i=0;i<strlen(s);i++)
		ans=(ans*base+(ll)s[i])%mod+p;
	return ans;
}
int main(){
	char s[10010];
	int n,sum;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		hash[i]=getHash(s);
	}
	sort(hash,hash+n);
	for(int i=0;i<n;i++)
		if(hash[i]!=hash[i+1])
			sum++;
	printf("%d",sum);
	return 0;
}


 
