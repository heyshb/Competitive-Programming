#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int N,fa[100010];
vector<int>e[100010];
LL down[100010],up[100010];
const int MOD = 1000000007;
bool leaf[100010];

void dfs(int x,int f)
{
	fa[x] = f;
	leaf[x] = true;
	LL m = 2;
	for (auto t:e[x])
	if (t != f)
	{
		leaf[x] = false;
		dfs(t,x);
		m *= down[t];
		m %= MOD;
	}
	down[x] = m;
	if (leaf[x]) down[x] = 1;
}

LL quick_pow(LL a,LL x)
{
	LL res = 1;
	while(x)
	{
		if (x & 1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return res;
}

LL rev(LL x)
{
	return quick_pow(x,MOD-2);
}

void dfs2(int x)
{
	LL m = 1;
	for (auto t:e[x]) if (t != fa[x]) m *= down[t];
	for (auto t:e[x])
	if (t != fa[x])
	{
		if (e[x].size() == 1) up[t] = 1;
		else up[t] = 2LL * up[x] * m % MOD * rev(down[t]) % MOD;
		dfs2(t);
	}
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	up[1] = 1;
	dfs2(1);
	//for (int i=1;i<=N;i++)printf("%d:%lld %lld\n",i,up[i],down[i]);
	LL ans = 0;
	for (int i=1;i<=N;i++)
	if (!leaf[i])
		ans = (ans + up[i] * down[i]) % MOD;
	else	
		ans = (ans + 2LL * up[i]) % MOD;
	printf("%lld\n",ans);
}
