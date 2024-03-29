#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
int x[maxn],n,total,k;
bool judge(int k){
	for(int i=1;i<k;i++){
		if(abs(k-i)==abs(x[k]-x[i])||x[k]==x[i])
			return false;
	} //判断与前面k行的皇后有没有产生冲突 
	return true;
} 
void backtrack(int t){
	if(t>n){
		total++;
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;
			if(judge(t))
				backtrack(t+1);
		}
	}
}
int main(){
	cin>>n;
	backtrack(1);
	cout<<total<<endl;
	return 0;
} 
