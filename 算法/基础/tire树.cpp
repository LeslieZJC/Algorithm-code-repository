#include <bits/stdc++.h>
#define maxn 26//每个节点下都有26个，空间换时间 
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
int search(const char *s){  //查找某个单词是否已经存在   
    trie *p=root; 
    while(p!=NULL&&*s!='\0') { 
        p=p->next[*s-'a']; 
        s++; 
    } 
    return (p!=NULL&&p->isStr==true);      //在单词结束处的标记为true时，单词才存在  
}
void del(trie *root){                      //释放整个字典树占的堆区空间  
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
    int n,m;                              //n为建立Trie树输入的单词数，m为要查找的单词数  
    char s[100];
	root=(trie*)malloc(sizeof(trie));
	for(int i=0;i<maxn;i++) 
        root->next[i]=NULL; 
    root->isStr=false; 
    scanf("%d",&n); 
    getchar(); 
    for(i=0;i<n;i++){                //先建立字典树  
        scanf("%s",s); 
        insert(s); 
    } 
    while(scanf("%d",&m)!=EOF){ 
        for(i=0;i<m;i++){                 //查找  
            scanf("%s",s); 
            if(search(s)==1) 
                printf("YES\n"); 
            else
                printf("NO\n"); 
        } 
        printf("\n");    
    } 
    del(root); 						 //释放空间很重要
	return 0;
} 
