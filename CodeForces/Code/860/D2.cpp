#include <bits/stdc++.h>

using namespace std;

const int MAXM = 200010;
const int MAXN = 200010;
int cnt = 0,u[MAXM],v[MAXM],w[MAXM];
int N,M; 
vector<int>e[MAXN];
bool vis[MAXN],fause[MAXN];
vector<int>a[MAXN];

void push(int U,int V,int W)
{
	if (U == 0 || V == 0 || W == 0) return;
	cnt++;
	u[cnt] = U;
	v[cnt] = V;
	w[cnt] = W;
}

void dfs(int x,int fa)
{
	vis[x] = true;
	for (auto t:e[x])
	if (t != fa)
	{
		if (!vis[t])
		{
			dfs(t,x);
			if (!fause[t]) a[x].push_back(t);
		}
		else
		{
			a[t].push_back(x);
		}
	}
	if (a[x].size() % 2 == 0)
	{
		for (int i=0;i<a[x].size();i+=2)
			push(a[x][i],x,a[x][i+1]);
	}
	else
	{
		fause[x] = true;
		for (int i=1;i<a[x].size();i+=2)
			push(a[x][i],x,a[x][i+1]);
		push(a[x][0],x,fa);
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++)
	{
		int U,V,W;
		scanf("%d%d",&U,&V);
		e[U].push_back(V);
		e[V].push_back(U);
	}
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=N;i++)
	if (!vis[i])
		dfs(i,0);
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)printf("%d %d %d\n",u[i],v[i],w[i]);
}
