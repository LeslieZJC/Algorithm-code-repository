#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXLEN 100
using namespace std;
void LCS(int m,int n,char a[],char b[],int c[][MAXLEN]){
	int i,j;
	for(i=0;i<=n;i++){
		c[0][i]=0;
	}
	c[1][0]=0;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(a[i-1]==b[j-1])
				c[1][j]=c[0][j-1]+1;
			else
				c[1][j]=max(c[0][j],c[1][j-1]);
		}
		for(j=1;j<=n;j++)
			c[0][j]=c[1][j];
		c[1][0]=0;
	}
	printf("%d",c[1][n]);
} 
int main(){
	char a[MAXLEN]="CEBJCEBDWABCBDAB";
	char b[MAXLEN]="BDCABCECWRDWXDA";
	int m=strlen(a),n=strlen(b);
	int c[2][MAXLEN];
	LCS(m,n,a,b,c);
	return 0;
}
