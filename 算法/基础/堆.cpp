//#include <stdio.h>
//#include <iostream>
//#include <vector> 
//#include <algorithm>
//using namespace std;
//int main(){
//	vector<int>v;
//	make_heap(v.begin(),v.end());
//	int n,m,k;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		scanf("%d",&m);
//		if(m==1){
//			scanf("%d",&k);
//			v.push_back(k);
//			make_heap(v.begin(),v.end());
//		}
//		else if(m==2){
//			sort(v.begin(),v.end());
//			printf("%d\n",v[0]);
//		}
//		else{
//			v.erase(v.begin()+0);
//			pop_heap(v.begin(),v.end());
//		}
//	}
//}
#include <cstdio>
#include <queue> //��Ҫ����ͷ�ļ�
using namespace std;
priority_queue<int,vector<int>,greater<int> >q; //�������ȶ��У����� 
int n,a,b;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&b);
            q.push(b); //��bѹ�����ȶ���
        }
        if(a==2){
            int ans=q.top(); //��ȡ�������ȼ���ߵ�Ԫ�ص�ֵ
            printf("%d\n",ans); //�����
        }
        if(a==3)
            q.pop(); //�����ȼ���ߵ�Ԫ�ص���
    }
}
