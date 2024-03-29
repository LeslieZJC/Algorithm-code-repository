#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
int w[maxn],v[maxn],c,num,maxm=0,cv,cw,x[maxn],total=0;
int add(int t){
	int sum;
	for(int i=t;i<=num;i++)
		sum+=v[i];
	return sum;
}
void backtrack(int t,int cv,int cw){
	if(t>num){
		total++;
		if(cv>maxm)
			maxm=cv;
		return;
	}
	else{
//		x[t]=1;
//		if((cv+add(t))>maxm)
//			if(cw+w[t]<=c)
//				backtrack(t+1,cv+v[t],cw+w[t]);
//		x[t]=0;
//		if(cw<=c)
//			if((cv+add(t+1))>maxm)
//				backtrack(t+1,cv,cw);
		if(cw+w[t]<=c){
            cw+=w[t];
            cv+=v[t];
            x[t]=1;
            backtrack(t+1,cv,cw);
            cw-=w[t];
            cv-=v[t];
            x[t]=0;
        }
        //不装入这个物品，直接搜索右边的节点
        if((cv+add(t+1))>=maxm){
            backtrack(t+1,cv,cw);
        }
	}
}
int main(){
	cin>>c>>num;
	for(int i=1;i<=num;i++){
		cin>>w[i];
		cin>>v[i];
	}
	backtrack(1,0,0);
	cout<<maxm<<endl<<total;
	return 0;
}
