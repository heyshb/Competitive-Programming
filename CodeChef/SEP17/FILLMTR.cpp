#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N,Q;
int fa[100010];
vector<int>e[100010];
pair<int,pair<int,int> >B[1000010];
bool vis[100010];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int col[100010];
bool cancol;

void dfs(int x)
{
	for (auto t:e[x])
	{ 
		if (col[t] == col[x]) 
		{
			cancol = false;
			return;
		}
		if (!col[t])
		{
			col[t] = 3 - col[x];
			dfs(t);
		}
	} 
}

bool solve()
{
	for (int i=1;i<=Q;i++)
	if (B[i].X == 0)
	{
		int x = B[i].Y.X, y = B[i].Y.Y;
		x = find(x);
		y = find(y);
		fa[x] = y;
	}
	for (int i=1;i<=Q;i++)
	if (B[i].X == 1)
	{
		int x = B[i].Y.X, y = B[i].Y.Y;
		x = find(x);
		y = find(y);
		if (x == y) return false;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cancol = true;
	for (int i=1;i<=N;i++)vis[i] = false;
	for (int i=1;i<=N;i++)
	if (!col[i]) col[i] = 1,dfs(i);
	return cancol;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&Q);
		for (int i=1;i<=N;i++)fa[i] = i,e[i].clear(), col[i] = 0;
		for (int i=1;i<=Q;i++)
			scanf("%d%d%d",&B[i].Y.X,&B[i].Y.Y,&B[i].X);
		puts(solve()?"yes":"no");
	}
}
