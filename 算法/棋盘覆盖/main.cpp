#include <stdlib.h>
#include <iostream>
#define  max 8
using namespace std;
int tile=1;
int Board[max][max];
void ChessBoard(int tr,int tc,int dr,int dc,int size){
	if(size==1)
		return;
	int t=tile++,s=size/2;
	if(dr<tr+s && dc<tc+s)
		ChessBoard(tr,tc,dr,dc,s);
	else{
		Board[tr+s-1][tc+s-1]=t;
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	if(dr<tr+s && dc>=tc+s)
		ChessBoard(tr,tc+s,dr,dc,s);
	else{
		Board[tr+s-1][tc+s-1]=t;
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	if(dr>=tr+s && dc<tc+s)
		ChessBoard(tr+s,tc,dr,dc,s);
	else{
		Board[tr+s][tc+s-1]=t;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}
	if(dr>=tr+s && dc>=tc+s)
		ChessBoard(tr+s,tc+s,dr,dc,s);
	else{
		Board[tr+s][tc+s]=t;
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
	}
} 
void printBoard(){
	int i,j;
	for(i=0;i<max;i++){
		for(j=0;j<max;j++)
			printf("%-3d ",Board[i][j]);
		printf("\n");
	}
	printf("\n");
}
int mark[100],n;
vector<int>ans;
void output(){
	
}
int divide(int n,int m){
	if(n==1){
		output()
		return 1;
	}
		
	if(m==1)
		return 1;
	if(n==m)
		return 1+divide(n,n-1);
	if(m>n)
		return divide(n,n);
	if(m<n)
		return divide(n,m-1)+divide(n-m,m);
}
void print(int sum,int deepth,int Max){
	if(sum==n){
		cout<<mark[0];
		for(int i=1;i<deepth;i++){
			cout<<"+"<<mark[i];
		}
		cout<<endl;
	}
	else if(sum<n){
		for(int i=Max;i>0;i--){
			mark[deepth]=i;
			print(sum+i,deepth+1,i);
		}
	}
}
int main(int argc, char** argv) {
//	int size=max;
//	ChessBoard(0,0,5,2,size);
//	printBoard();

	printf("%d\n",divide(10,10));
	n=10;
	print(0,0,20);
	return 0;
}
