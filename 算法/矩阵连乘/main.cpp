#include "iostream"
using namespace std;
 
#define N 7  //NΪ7��ʵ�ʱ�ʾ��6������
/*
*���������캯��������m[][]��s[][]
*m�д洢��ֵ�Ǽ����������С�˷�����������m[1][5]����A1A2A3A4A5����С�˷�����
*s�д洢���ǻ�ȡ��С�˷�����ʱ�Ķ����㣬s[1][5]��Ӧ�ľ�����β��A1A2A3A4A5,
*����S[1][5]=3�ɱ�ʾ��(A1A2A3)(A4A5)����Ȼ�ڲ����������������A1A2A3
*/
int MatrixChain(int p[], int n, int m[][N], int s[][N]){
    for(int i=1;i<=n;i++){     //��������ֻ��һ������ʱ������Ϊ0��ע��m[0][X]ʱδʹ�õ�
        m[i][i]=0;
    }
    for(int r=2;r <= n;r++){    //����������,�ӳ���Ϊ2��ʼ
        for(int i=1;i <= n-r+1;i++){    //���������ȣ����������Ŀ���ʼ��
            int j = i+(r-1);  //��������ĩβ����ע��r-1����Ϊ������Ϊ2ʱ��ʵ��������+1
            m[i][j] = m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];   //��������õĻ��ַ�������ֱ���ұ߿���������������Ҳ�ɺϲ��������forѭ����
            s[i][j]=i;
            for(int k=i+1;k<j;k++){   //�����潫�������i+1��ʼ�����Զ����ĵ�ֱ��j-1Ϊֹ
                int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
 
            }
 
        }
    }
}
/*
*׷�ٺ��������������i,j�޶���Ҫ��ȡ�ľ�������ʼĩλ�ã�s�洢������
*/
void Traceback(int i,int j, int s[][N]){
    if(i==j)       //�ع�����
    {
        cout<<"A"<<i;
    }
    else       //������Ѷϵ�һ��Ϊ�������ż����ݹ�
    {
        cout<<"(";
        Traceback(i,s[i][j],s);
        Traceback(s[i][j]+1,j,s);
        cout<<")";
    }
}
int LookUpChain(int i,int j){
	if(i==j)
		return 0;
	for(int k=i;k<j-1;k++){
		int u=LookUpChain(i,k)+LookUpChain(k+1,j)+p[i]p[k+1]p[j+1];
		if(u<min)
			min=u;
	}
}
int main(){
	int p[N]={30,35,15,5,10,20,25};
	int m[N][N],s[N][N];
 
	MatrixChain(p,N-1,m,s);//N-1��Ϊֻ����������
    Traceback(1,6,s);
	return 0;
}
