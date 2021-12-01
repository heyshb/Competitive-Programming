#include<bits/stdc++.h>
using namespace std;
int n,ans;
char ch[20];
int calc(){
	int res=0;
	for (int i=0;i<n;i++){
		int tmp=0;
		for (int j=i;j<n;j++){
			if (ch[j]=='r') tmp++;
			if (tmp&1) res++;
		}
	}
	return res;
}
void dfs(int x,int y){
	if (x==y){
		if (ans==calc()) printf("%s\n",ch);
		return;
	}
	ch[x]='b';
	dfs(x+1,y);
	ch[x]='r';
	dfs(x+1,y);
}
int main(){
	scanf("%d",&n);
	for (int i=n;i>0;i-=2) ans+=i;
	printf("%d\n",ans);
	dfs(0,n);
}
