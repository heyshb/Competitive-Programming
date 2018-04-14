#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
vector<int>e[100010];
int col[100010];
bool ok = true;

void dfs(int x)
{
	for (auto t:e[x])
	if (!col[t])
	{
		col[t] = 3-col[x];
		dfs(t);
	}	
	else
	{
		if (col[t] + col[x] != 3) ok = false;
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1;i<=N;i++)
	if (!col[i]) col[i] = 1, dfs(i);
	printf("%d\n",!ok);
}

