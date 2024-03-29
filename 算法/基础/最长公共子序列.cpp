#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXLEN 100
using namespace std;
char a[MAXLEN];
char b[MAXLEN];
int c[2][MAXLEN];
int main(){
	int num,i,j;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
		scanf("%c",&a[i]);
	getchar();
	for(i=1;i<=num;i++)
		scanf("%c",&b[i]);
	for(i=0;i<=num;i++){
		c[0][i]=0;
	}
	c[1][0]=0;
	for(i=1;i<=num;i++){
		for(j=1;j<=num;j++){
			if(a[i]==b[j])
				c[1][j]=c[0][j-1]+1;
			else
				c[1][j]=max(c[0][j],c[1][j-1]);
		}
		for(j=0;j<=num;j++){
			c[0][j]=c[1][j];
			c[1][0]=0;
		}	
	}
	printf("%d",c[1][num]);
	return 0;
}
