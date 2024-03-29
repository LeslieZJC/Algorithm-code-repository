//#include <stdio.h>
//#include <iostream>
//#include <string.h>
//using namespace std; 
//int main(int argc, char** argv) {
//	
//	char a[100]="HXBSNIXBJKXSAXSXWDEC";
//	char b[100]="DEWUDIHBWBWBDWDX";
//	int m[100][100];
//	int x=strlen(a),y=strlen(b);
//	for(int i=0;i<=x;i++){
//	    m[i][0]=0;
//	}
//	for(int j=1;j<=y;j++){
//	    m[0][j]=0;
//	}
//	for(int i=0;i<=x;i++){
//		for(int j=0;j<y;j++)
//			printf("%d ",m[i][j]);
//		printf("\n");
//	}
//		
//	for(int i=1;i<=x;i++){
//		for(int j=1;i<=y;j++){
//			if (a[i-1]==b[j-1]){
//                m[i][j]=m[i-1][j-1]+1;printf("%d ",m[i][j]);
//            }
//			else
//                m[i][j]=max(m[i-1][j],m[i][j-1]);			
//		}
//	}
//	for(int i=0;i<=x;i++){
//		for(int j=0;j<y;j++)
//			
//		printf("\n");
//	}
//	return 0;
//}
#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXLEN 100
using namespace std;
int b[MAXLEN][MAXLEN];
void LCSLength(char *x,char *y,int m, int n,int c[][MAXLEN],int b[][MAXLEN]){
    int i,j;
	for(i=0;i<=m;i++){
	    c[i][0]=0;
	}
	for(j=1;j<=n;j++){
	    c[0][j]=0;
	}
	for(i=1;i<=m;i++){
	   for(j=1;j<=n;j++){
	       if(x[i-1]==y[j-1]){
		     c[i][j]=c[i-1][j-1]+1;  //c[i][j]来源于前一行前一列，即↖
			 b[i][j]=0;
//			 printf("%d ",c[i][j]);             
		   }
		    else if(c[i-1][j]>=c[i][j-1]){
			    c[i][j]=c[i-1][j];   //c[i][j]来源于前一行前一列，即↑
				b[i][j]=1;  
			}
			else{
			    c[i][j]=c[i][j-1];  //c[i][j]来源于前一行前一列，即←
				b[i][j]=-1;
			}
//			else
//				c[i][j]=max(c[i-1][j],c[i][j-1]);
	    }
	}
}
void PrintLCS(int b[][MAXLEN],char *x,int i,int j)
{
   if(i==0||j==0){
       return ;
   }
   if(b[i][j]==0){
       PrintLCS(b,x,i-1,j-1);
	   printf("%c ",x[i-1]);
   }
   else if(b[i][j]==1){
       PrintLCS(b,x,i-1,j);
	}
   else{
       PrintLCS(b,x,i,j-1);
   }
}
int main()
{
    char x[MAXLEN]="ABCBDAB";
	char y[MAXLEN]="BDCABA";
	int c[MAXLEN][MAXLEN];
	int m,n;
//	printf("输入第一个字符串:\n");
//	gets(x);
//	printf("输入第二个字符串:\n");
//	gets(y);
	m=strlen(x);
	n=strlen(y);
	LCSLength(x,y,m,n,c,b);
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	printf("最长公共子序列为：");
	printf("\n");
	return 0;
} 
