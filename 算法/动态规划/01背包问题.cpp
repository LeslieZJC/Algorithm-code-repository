#include <iostream>
#define N 5    //商品的种类
#define W 11   //背包的最大承重
using namespace std;
/*
动态规划算法解决01背包问题
result[N + 1][W + 1]：存储最终的结果
w[N + 1]：存储各商品的重量
v[N + 1]：存储各商品的价值
*/
void knapsack(int result[N+1][W+1],int w[N+1],int v[N+1]){
    int i,j;//逐个遍历每个商品
    for(i=1;i<=N;i++){//求出从 1 到 W 各个载重对应的最大收益
        for(j=1;j<=W;j++) {
            if (j<w[i])//如果背包载重小于商品总重量，则该商品无法放入背包，收益不变
                result[i][j]=result[i-1][j];
            else//比较装入该商品和不装该商品，哪种情况获得的收益更大，记录最大收益值
                result[i][j]=max(result[i-1][j],v[i]+result[i-1][j-w[i]]);
        }
    }
}
//追溯选中的商品
void select(int result[N+1][W+1], int w[N+1],int v[N+1]){
    int n=N;
    int bagw=W;//逐个商品进行判断
    while(n>0) {//如果在指定载重量下，该商品对应的收益和上一个商品对应的收益相同，则表明未选中
        if(result[n][bagw]==result[n-1][bagw])
            n--;
        else {//输出被选用商品的重量和价值
            printf("(%d,%d) ",w[n],v[n]); //删除被选用商品的承重，以便继续遍历
            bagw=bagw-w[n];
            n--;
        }
    }
}
int main(){
    int w[N+1]={0,1,2,5,6,7};            //商品的承重
    int v[N+1]={0,1,6,18,22,28};        //商品的价值
    int result[N+1][W+1]={0};                        //记录统计数据
    knapsack(result,w,v);
    printf("背包承重为%d,最大收益为 %d\n",W,result[N][W]);
    printf("选择了：");
    select(result,w,v);
    return 0;
}
