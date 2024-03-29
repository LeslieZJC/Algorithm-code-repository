#include <bits/stdc++.h>
#define maxn 26//ÿ���ڵ��¶���26�����ռ任ʱ�� 
typedef struct trie{
	bool isStr;
	trie *next[maxn];
}trie;
trie *root;
void insert(char *s){
	if(root==NULL||*s=='\0')
		return;
	trie* p=root;
	int i;
	while(*s!='\0'){
		if(p->next[*s-'a']==NULL){
			trie* temp=(trie*)malloc(sizeof(trie));
			for(i=0;i<maxn;i++) 
        		root->next[i]=NULL;
        	temp->isStr=false;
			p->next[*s-'a']=temp;
			p=p->next[*s-'a'];
		}
		else{
			p=p->next[*s-'a'];
		}
		s++;
	}
	p->isStr=true;
}
int search(const char *s){  //����ĳ�������Ƿ��Ѿ�����   
    trie *p=root; 
    while(p!=NULL&&*s!='\0') { 
        p=p->next[*s-'a']; 
        s++; 
    } 
    return (p!=NULL&&p->isStr==true);      //�ڵ��ʽ������ı��Ϊtrueʱ�����ʲŴ���  
}
void del(trie *root){                      //�ͷ������ֵ���ռ�Ķ����ռ�  
    int i; 
    for(i=0;i<maxn;i++){ 
        if(root->next[i]!=NULL){ 
            del(root->next[i]); 
        } 
    } 
    free(root); 
} 
int main(){
	int i; 
    int n,m;                              //nΪ����Trie������ĵ�������mΪҪ���ҵĵ�����  
    char s[100];
	root=(trie*)malloc(sizeof(trie));
	for(int i=0;i<maxn;i++) 
        root->next[i]=NULL; 
    root->isStr=false; 
    scanf("%d",&n); 
    getchar(); 
    for(i=0;i<n;i++){                //�Ƚ����ֵ���  
        scanf("%s",s); 
        insert(s); 
    } 
    while(scanf("%d",&m)!=EOF){ 
        for(i=0;i<m;i++){                 //����  
            scanf("%s",s); 
            if(search(s)==1) 
                printf("YES\n"); 
            else
                printf("NO\n"); 
        } 
        printf("\n");    
    } 
    del(root); 						 //�ͷſռ����Ҫ
	return 0;
} 
