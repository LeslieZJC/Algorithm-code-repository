//#include <bits/stdc++.h>
//#define maxn 1001
//using namespace std;
//int map1[maxn][maxn],ans[maxn],n,m,total=0;
//void dfs(int x,int t){
//	int flag=0;
//	for(int i=1;i<=n;i++){
//		if(map1[x][i]==1)	
//			dfs(i,t);
//		else{
//			flag++;
//			if(flag==n){
//				ans[t]++;
//				return;
//			}
//		}
//	}
//}
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=m;i++){
//		int x,y;
//		cin>>x>>y;
//		map1[y][x]=1;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%d ",map1[i][j]);		
//		}
//		printf("\n");
//	}
//	for(int i=1;i<=n;i++){
//		dfs(i,i);
//	}
//	printf("%d",total);
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
#define Max 5005
vector<int > Graph[Max];
typedef long long int ll;
int d[Max];
void solve(int n);
int dfs(int i); //�Ӷ���i������߼������ߵ�·������
ll res=0;
int dp[Max]; //��ĳһ��i������߼������ߵ�·������
int main()
{
    int n,m;
    cin>>n>>m;
    int x1,x2;
    memset(d,0, sizeof(d));
    memset(dp,0, sizeof(dp));
    for(int i=1;i<=m;i++)
    {
        cin>>x1>>x2;
        Graph[x1].push_back(x2);//x2�Ե�x1
        d[x2]=1; //�������ȵĽڵ�
    }
    solve(n);
    cout<<res%80112002;
    return 0;
}

int dfs(int i) //�Ӷ���i������߼������ߵ�·������
{
    if(Graph[i].size()==0)
    {
        return 1;
    }
    if(dp[i])
    {
        return dp[i];
    }
    for(int j=0;j<Graph[i].size();j++)
    {
        int v=Graph[i][j];
        dp[i]=(dp[i]+dfs(v))%80112002; //�������ܴ󡣡���
    }
    return dp[i];
}

void solve(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(!d[i]) //���Ϊ0�Ľڵ�
        {
            res=(res+dfs(i))%80112002;
        }
    }
}
