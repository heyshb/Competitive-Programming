#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 200010;
const int MAXDEP = 20;
struct query{int u,v,id;}q[100010];

int N,M;
LL cnt,ans;
int top,blonum,blo = 600;
LL res[MAXN],p[MAXN];
int fa[MAXN][MAXDEP+1],dep[MAXN];
int dfn[MAXN],bl[MAXN],st[MAXN];
int col[MAXN],v[MAXN];
int ct[2][MAXN];
int size[MAXN];
bool vis[MAXN];
vector<int>e[MAXN];
int tmc = 0;
bool cmp(query a,query b)
{
	if (bl[a.u] == bl[b.u])
		return dfn[a.v] < dfn[b.v];
	return bl[a.u] < bl[b.u];
}

void dfs(int x,int ff)
{
	size[x] = 1;
	dfn[x] = ++ tmc;
	fa[x][0] = ff;
	for (int i=1;i<=MAXDEP;i++)fa[x][i] = fa[fa[x][i-1]][i-1];
	for (auto t:e[x])
	if (t != ff)
	{
		dep[t] = dep[x] + 1;
		dfs(t,x);
		size[x] += size[t];
		if (size[x] >= blo)
		{
			blonum++;
			for (int k=1;k<=size[x];k++)bl[st[top--]] = blonum;
			size[x] = 0;
		}
	}
	st[++top] = x;
}

int lca(int x,int y)
{
	if (dep[x] < dep[y]) swap(x,y);
	int delta = dep[x] - dep[y];
	for (int i=0;i<=MAXDEP;i++)
		if (delta & (1<<i)) x = fa[x][i];
	for (int i=MAXDEP;i>=0;i--)
	if (fa[x][i] != fa[y][i])
	{
		x = fa[x][i];
		y = fa[y][i];
	}
	if (x == y) return x;
	return fa[x][0];
}

LL calc(LL V)
{
	LL v1 = ct[0][V], v2 = ct[1][V];
	return v1 * v2;
}

void rev(int x)
{
	LL tmp;
	if (!vis[x])
	{
		vis[x] = 1;
		ans -= calc(v[x]);
		ct[col[x]][v[x]]++;
		ans += calc(v[x]);
	}
	else
	{
		vis[x] = 0;
		ans -= calc(v[x]);
		ct[col[x]][v[x]]--;
		ans += calc(v[x]);
	}
}

void solve(int u,int v)
{
	while(u != v)
	{
		if (dep[u] > dep[v])
			rev(u), u = fa[u][0];
		else
			rev(v), v = fa[v][0];
	}
}

unordered_map<int,int>num;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&col[i]);
	int tmpcnt = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%lld",&v[i]);
		if (!num[v[i]]) num[v[i]] = ++tmpcnt;
	}
	for (int i=1;i<=N;i++)v[i] = num[v[i]];
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	blonum++;
	while(top) bl[st[top--]] = blonum;
	scanf("%d",&M);
	for (int i=1;i<=M;i++)
	{
		int U,V;
		scanf("%d%d",&U,&V);
		if (dfn[U] > dfn[V]) swap(U,V);
		q[i].u = U;q[i].v = V;
		q[i].id = i;
	}
	ans = 0;
	sort(q+1,q+M+1,cmp);
	int t = lca(q[1].u,q[1].v);
	solve(q[1].u,q[1].v);
	rev(t);res[q[1].id] = ans;
	rev(t);
	for (int i=2;i<=M;i++)
	{
		solve(q[i-1].u,q[i].u);
		solve(q[i-1].v,q[i].v);
		t = lca(q[i].u,q[i].v);
		rev(t);
		res[q[i].id] = ans;
		rev(t);
	}
	for (int i=1;i<=M;i++)printf("%lld\n",res[i]);
}
