#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
int col[100010];
vector<int>e[100010];
int cnt[3];

bool dfs(int x)
{
	cnt[col[x]]++;
	for (auto t:e[x])
	if (col[t])
	{
		if (col[t] == col[x]) return false;
	}
	else
	{
		col[t] = 3 - col[x];
		if (!dfs(t)) return false;
	}
	return true;
}

typedef long long LL;

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
	col[1] = 1;
	long long ans = 0;
	if (dfs(1))
	{
		ans += LL(cnt[2]) * LL(cnt[1]);
		ans -= M;
	}
	else
	{
		ans += LL(N) * LL(N-1) / 2;
		ans -= M;
	}
	printf("%lld\n",ans);
}
