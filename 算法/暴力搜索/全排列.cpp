//#include <iostream>
//#include <stdio.h>
//#include <cstring>
//#include <algorithm>
//#define MAX 100
//int num,s[MAX];
//void swap(int n,int m){
//	int temp=s[n];
//	s[n]=s[m];
//	s[m]=temp;
//}
//void dfs(int n){
//	if(n==(num-1)){
//		for(int i=0;i<num;i++)
//			printf("%5d",s[i]);	
//		printf("\n");
//	}
//	else{
//		for(int i=n;i<num;i++){
//			swap(n,i);
//			dfs(n+1);
//			swap(n,i);
//		}
//	}
//}
//int main(){
//	scanf("%d",&num);
//	for(int i=0;i<num;i++)
//		s[i]=i+1;
//	dfs(0);
//	return 0;
//}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void show(int a[],int len){
//    for(int i=0;i<len-1;i++){
//        printf("    %d",a[i]);
//    }
//    printf("    %d\n",a[len-1]);
//}
//
//int hash_map[10] = {0}; //hash数组用来标记哪些数字已经被使用过
//int b[10] = {0};
//int j = 0;
//void my_next_permutation(int a[],int len){
//    for(int i = 0; i < len; i++){
//        for(;hash_map[i] == 1;i++);    //始终从小到大使用 没使用过的数字
//        if(i != len){
//            hash_map[i] = 1;
//            b[j++] = a[i];
//            if(j == len) show(b,len);
//            my_next_permutation(a,len);
//            j--;
//            hash_map[i] = 0;
//        }
//    }
//}
//int main(){
//	int num,s[100];
//	scanf("%d",&num);
//	for(int i=0;i<num;i++)
//		s[i]=i+1;
//    my_next_permutation(s,num);
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int n,vis[100],ans[100];
void print(){
//输出已经选择好的排列 
    for(int i=1;i<=n;i++)
        printf("%5d",ans[i]);
    puts("");
}void search(int k){
//搜索到了第 k 格 
    if(k==n){//满了，输出
        print();
        return;
    }for(int i=1;i<=n;i++){//循环作选择 
        if(!vis[i]){//如果没用过 
            vis[i]=1;ans[k+1]=i;//用它 
            search(k+1);//填充下一个格子  
            vis[i]=0;//把他拿出来，换一个填 
        }
    }
}int main(){
    cin>>n;
    search(0);//从 0 开始搜索 
    return 0;
}
