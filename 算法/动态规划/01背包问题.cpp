#include <iostream>
#define N 5    //��Ʒ������
#define W 11   //������������
using namespace std;
/*
��̬�滮�㷨���01��������
result[N + 1][W + 1]���洢���յĽ��
w[N + 1]���洢����Ʒ������
v[N + 1]���洢����Ʒ�ļ�ֵ
*/
void knapsack(int result[N+1][W+1],int w[N+1],int v[N+1]){
    int i,j;//�������ÿ����Ʒ
    for(i=1;i<=N;i++){//����� 1 �� W �������ض�Ӧ���������
        for(j=1;j<=W;j++) {
            if (j<w[i])//�����������С����Ʒ�������������Ʒ�޷����뱳�������治��
                result[i][j]=result[i-1][j];
            else//�Ƚ�װ�����Ʒ�Ͳ�װ����Ʒ�����������õ�������󣬼�¼�������ֵ
                result[i][j]=max(result[i-1][j],v[i]+result[i-1][j-w[i]]);
        }
    }
}
//׷��ѡ�е���Ʒ
void select(int result[N+1][W+1], int w[N+1],int v[N+1]){
    int n=N;
    int bagw=W;//�����Ʒ�����ж�
    while(n>0) {//�����ָ���������£�����Ʒ��Ӧ���������һ����Ʒ��Ӧ��������ͬ�������δѡ��
        if(result[n][bagw]==result[n-1][bagw])
            n--;
        else {//�����ѡ����Ʒ�������ͼ�ֵ
            printf("(%d,%d) ",w[n],v[n]); //ɾ����ѡ����Ʒ�ĳ��أ��Ա��������
            bagw=bagw-w[n];
            n--;
        }
    }
}
int main(){
    int w[N+1]={0,1,2,5,6,7};            //��Ʒ�ĳ���
    int v[N+1]={0,1,6,18,22,28};        //��Ʒ�ļ�ֵ
    int result[N+1][W+1]={0};                        //��¼ͳ������
    knapsack(result,w,v);
    printf("��������Ϊ%d,�������Ϊ %d\n",W,result[N][W]);
    printf("ѡ���ˣ�");
    select(result,w,v);
    return 0;
}
