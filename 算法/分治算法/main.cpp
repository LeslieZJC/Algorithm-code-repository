#include <iostream>
#include "stdlib.h"
int random(int a,int b){
    srand(0);
	return rand()%(b-a)+a;
}
void exchange(int *a,int *b){
	int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int p,int r){
	int x=a[p];
	int i=p,j=r+1;
	while(true){
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)
			break;
		exchange(&a[i],&a[j]);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}
int random_partition(int a[],int p,int r){
	int i=random(p,r);
    exchange(&a[r],&a[i]);
	return partition(a,p,r);
}
void random_quicksort(int a[],int p,int r){
	int q;
	if (p<r){
	    q=random_partition(a,p,r);
	    random_quicksort(a,p,q-1);
	    random_quicksort(a,q+1,r);
	}
}
int randomSelect(int a[],int p,int r,int k){
	if(p==r)
		return a[p];
	int pos=random_partition(a,p,r);
}
int main(){
	int a[100];
	int j; 
	printf("请输入待排序的数组的大小：");
	scanf("%d",&j);
	printf("请输入待排序的数组：\n");
	for(int i=0;i<j;i++)
		scanf("%d",&a[i]);
	random_quicksort(a,0,j-1);
	for (int i=0;i<=j-1;i++)
	    printf("%d ",a[i]);
	return 0;
}
