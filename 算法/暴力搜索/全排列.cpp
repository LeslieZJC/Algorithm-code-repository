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
//int hash_map[10] = {0}; //hash�������������Щ�����Ѿ���ʹ�ù�
//int b[10] = {0};
//int j = 0;
//void my_next_permutation(int a[],int len){
//    for(int i = 0; i < len; i++){
//        for(;hash_map[i] == 1;i++);    //ʼ�մ�С����ʹ�� ûʹ�ù�������
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
//����Ѿ�ѡ��õ����� 
    for(int i=1;i<=n;i++)
        printf("%5d",ans[i]);
    puts("");
}void search(int k){
//�������˵� k �� 
    if(k==n){//���ˣ����
        print();
        return;
    }for(int i=1;i<=n;i++){//ѭ����ѡ�� 
        if(!vis[i]){//���û�ù� 
            vis[i]=1;ans[k+1]=i;//���� 
            search(k+1);//�����һ������  
            vis[i]=0;//�����ó�������һ���� 
        }
    }
}int main(){
    cin>>n;
    search(0);//�� 0 ��ʼ���� 
    return 0;
}
