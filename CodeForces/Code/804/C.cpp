#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
int col[300010];
vector<int>e[300010]; 
vector<int>s[300010];
bool vis[300010];

void dfs(int x,int fa)
{
	for (auto t:s[x])
		vis[col[t]] = true;
	int now = 1;
	for (auto t:s[x])
	if (!col[t])
	{
		while(vis[now]) now++;
		col[t] = now;
		vis[now] = true;
	}
	for (auto t:s[x])
		vis[col[t]] = false;
	for (int i=0;i<e[x].size();i++)
	if (e[x][i] != fa)
		dfs(e[x][i],x);
}

int main()
{
	scanf("%d%d",&N,&M);
	int ans = 0;
	for (int i=1;i<=N;i++)
	{
		int S,tmp;
		scanf("%d",&S); 
		ans = max(ans,S);
		for (int j=1;j<=S;j++)
		{
			scanf("%d",&tmp);
			s[i].push_back(tmp);
		}
	}
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	memset(col,0,sizeof(col));
	memset(vis,false,sizeof(vis));
	dfs(1,0);
	for (int i=1;i<=M;i++)
		if (!col[i])
			col[i] = 1;
	if (ans == 0)
		ans = 1;
	printf("%d\n",ans);
	for (int i=1;i<=M;i++)printf("%d%c",col[i]," \n"[i==M]);
}
