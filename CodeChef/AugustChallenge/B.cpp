#include <bits/stdc++.h>

using namespace std;

int v[100010],dfn[100010],low[100010];
int stac[100010],top,size[100010],tmn,cnt;
bool instack[100010];

void dfs(int x)
{
	dfn[x]=low[x]=++tmn;
	stac[++top]=x;
	instack[x]=true;
	if (!dfn[v[x]])
	{
		dfs(v[x]);
		low[x]=min(low[x],low[v[x]]);
	}
	else if (instack[v[x]])
		low[x]=min(low[x],dfn[v[x]]);
	int now;
	if (low[x]==dfn[x])
	{
		cnt++;
		do
		{
			now=stac[top--];
			instack[now]=false;
			size[cnt]++;
		}
		while(now!=x);
	}
}

int main()
{
	int T,N;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for (int i=0;i<N;i++)
		{
			scanf("%d",&v[i]);
			v[i]=v[i]+i+1;
			v[i]%=N;
			printf("V %d\n",v[i]);
		}
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(size,0,sizeof(size));
		tmn=0;
		cnt=0;
		memset(instack,false,sizeof(instack));
		for (int i=0;i<N;i++)
		if (!dfn[i]) 
			dfs(i);
		int ans=0;
		for (int i=1;i<=cnt;i++)if (size[i]>1) ans+=size[i];
		printf("%d\n",ans);
	}
}
