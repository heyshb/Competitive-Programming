#include <bits/stdc++.h>

using namespace std;

int a[100010],b[100010],N,fa[100010];
typedef long long LL;
LL s[100010],ans[100010],MAXV;
bool done[100010];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
} 

void uno(int x,int y)//L,R
{
	//printf("UNO%d %d\n",x,y );
	x=find(x);
	y=find(y);
	fa[y]=x;
	s[x]+=s[y];
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		fa[i]=i;
		s[i]=a[i];
	}
	memset(done,false,sizeof(done));
	MAXV=0;
	for (int i=1;i<=N;i++)scanf("%d",&b[i]);
	for (int i=N;i>=1;i--)
	{
		ans[i]=MAXV;
		if (b[i]-1>0 && done[b[i]-1]) uno(b[i]-1,b[i]);
		if (b[i]+1<=N && done[b[i]+1]) uno(b[i],b[i]+1);
		//printf("%d\n",i);
		//for (int i=1;i<=N;i++)printf("%I64d ",s[i]);puts("");
		done[b[i]]=true;
		MAXV=max(MAXV,s[find(b[i])]);
		//printf("%I64d\n",MAXV);
		
	}
	for (int i=1;i<=N;i++)printf("%I64d\n",ans[i]);
}
