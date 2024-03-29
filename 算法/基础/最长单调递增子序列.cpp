//#include <stdio.h>
//#include <iostream>
//#include <string.h>
//#define MAXLEN 100
//void dp(int m,int a[],int **c,int t[]){
//	int i,j,k,max=0,pos=0;
//	for(i=0;i<m;i++){
//		t[i]=0;k=i;c[i][0]=a[i];
//		for(j=0;j<m;j++){
//			if(a[k]>=c[i][j]){
//				c[i][j+1]=a[k];
//				t[i]=t[i]++;
//				k++;
//			}
//			else{
//				c[i][j+1]=c[i][j];
//				k++;
//			}
//		}
//	}
//	for(i=1;i<=m;i++)
//		for(j=1;j<=m;j++)
//			printf("%d ",c[i][j]);
//	for(i=0;i<m;i++){
//		if(t[i]>max){
//			max=t[i];
//			pos=i+1;
//		}
//	}
//	for(i=1;i<=m;i++){
//		if(c[pos][i]!=c[pos][i-1])
//			printf("%d ",c[pos][i-1]);
//	}
//} 
//int main(){
//	int a[16]={2,3,7,4,2,5,0,9,10,3,2,7,3,11,8,15};
//	int c[16][16];
//	int t[16];
//	int m=16;
//	dp(m,a,(int**)c,t);
//} 
#include <iostream>
using namespace std;
int lis(int arr[],int len){
    int longest[len];
    for(int i=0;i<len;i++){
        longest[i]=1;
    }
    for(int j=1;j<len;j++){
        for(int i=0;i<j;i++){
            if(arr[j]>arr[i]&&longest[j]<longest[i]+1){// 注意longest[j] 小于 longest[i]+1 不能省略
                longest[j]=longest[i]+1;// 计算以arr[j]结尾的序列的最长递增子序列的长度
            }
        }
    }
    int max=0;
    for (int j=0;j<len;j++){
        cout<<"longest["<<j<<"]="<<longest[j]<<endl;
        if(longest[j]>max)max=longest[j];// 从longest[j]中找出最大值，即为最长长度
    }
    return max;
}
int main(){
    int arr[]={5,2,8,6,3,6,9,7};// 测试数组
    cout<<"The Length of Longest Increasing Subsequence is "<<lis(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
