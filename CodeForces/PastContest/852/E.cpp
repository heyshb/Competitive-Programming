#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int N,fa;
vector<int>e[100010];
LL down[100010][2],up[100010][2];
const int MOD = 1000000007;

void dfs(int x,int f)
{
	fa[x] = f;
	LL m0 = 1, m1 = 1;
	for (auto t:e[x])
	if (t != f)
	{
		dfs(t,x);
		m0 *= down[t][0];
		m1 *= down[t][1];
		m0 %= MOD;
		m1 %= MOD;
	}
	down[x][0] = down[x][1] = (m0 + m1) % MOD;
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
	for (auto t:e[x])
	if (t != fa[x])
	{
		
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
	dfs1(1,0);
	up[1][0] = 1;
	dfs2(1);
}
