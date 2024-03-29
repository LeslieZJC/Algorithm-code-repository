#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tot=0,k=0;//n�˵�������m������tot��¼���մ𰸣�k�Ѿ������˶��ٱ� 
int fat[200010];//��¼�����ϴ� 
struct node
{
	int from,to,dis;//�ṹ�崢��� 
}edge[200010];
bool cmp(const node &a,const node &b)//sort���򣨵�Ȼ��Ҳ���Կ��ţ� 
{
	return a.dis<b.dis;
}
int father(int x)//�Ҽ����ϴ󣬲��鼯��һ���� 
{
	if(fat[x]!=x)
	return father(fat[x]);
	else return x;
}
void unionn(int x,int y)//�������壬���鼯��һ���� 
{
	fat[father(y)]=father(x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].dis);//����ߵ���Ϣ 
	}
	for(int i=1;i<=n;i++) fat[i]=i;//�Լ��ʼ�����Լ����ϴ� ����ʼ���� 
	sort(edge+1,edge+1+m,cmp);//��Ȩֵ����kruskal�����֣� 
	for(int i=1;i<=m;i++)//��С������� 
	{
		if(k==n-1) break;//n������Ҫn-1�������� 
		if(father(edge[i].from)!=father(edge[i].to))//���粻��һ�����壬����¼�㣩 
		{
			unionn(edge[i].from,edge[i].to);//���� 
			tot+=edge[i].dis;//��¼��Ȩ 
			k++;//�����ӱ���+1 
		}
	}
	if(k==n-1)
		printf("%d",tot);
	else
		printf("orz");
	return 0;
}
