#include <iostream>
using namespace std;
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
void maxNum(int a[],int n){
	int s[n],sum,posL=0,posR=0;
	s[0]=a[0],sum=s[0];
	for(int i=1;i<n;i++){
		s[i]=max(s[i-1]+a[i],a[i]);
		if(s[i]>sum){
			sum=s[i];
			if(s[i]==a[i]){
				posL=i;
			}
			posR=i;	
		}
	}
	printf("该数组从%d---%d的子段和最大，为：%d",posL+1,posR+1,sum);
} 
int maxSum(int n,int *a){
	int sum=0,b=0;
	for(int i=1;i<=n;i++){
		if(b>0)
			b+=a[i];
		else
			b=a[i];
		if(b>sum)
			sum=b;
	}
	return sum;
}
//3 8 2 6 12 4 19 6 最长连续上升子序列
void maxUp(int a[],int n){
	int maxSize,s[n],size=0,posR=0;
	s[0]=a[0],maxSize=0;
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]){
			size++;
			s[i]=size;
		}
		else{
			size=0;
			s[i]=size;
		}
		if(s[i]>maxSize){
			maxSize=s[i];
			posR=i;
		}
	}
	printf("原串为：\n");
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
	printf("最长连续上升子序列为：%d，为序号%d---%d,子序列为：\n",maxSize+1,posR-maxSize+1,posR+1);
	for(int i=posR-maxSize;i<posR+1;i++)
		printf("%d  ",a[i]);
} 
int main(int argc, char** argv) {
//	int n;
//	printf("请输入待计算的数组大小：\n");
//	cin>>n;
//	int a[n];
//	printf("请输入该数组：\n");
//	for(int i=0;i<n;i++)
//		scanf("%d",&a[i]); 
//	printf("%d",maxNum(a,n));

//	int a[10]={-2,-1,-4,5,9,-8,7,6,-9,2};
//	maxNum(a,10);
//	printf("\n%d",maxSum(10,a));
	
	int b[10]={1,3,-2,-1,2,6,7,1,5,2};
	maxUp(b,10);
	printf("\n");
	int c[10]={1,3,-2,-1,-4,-3,-2,1,5,8};
	maxUp(c,10);
	printf("\n");
	int d[10]={1,3,4,5,6,7,-2,1,5,8};
	maxUp(d,10);
	return 0;
}
