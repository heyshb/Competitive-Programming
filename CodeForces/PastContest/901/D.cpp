#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;

typedef long long LL;

const int MAXN = 400010;

int n, m;

int L[MAXN], R[MAXN];
LL f[MAXN];
vector<pair<int,int> > E[MAXN];
int a[MAXN],dep[MAXN],vis[MAXN];
int NICO;

int dfs(int u,int fa,int dp,int num)
{
	dep[u] = dp;
	LL now = a[u];
	for (auto v:E[u])
	{
		int to = v.first, en = v.second;
		if (to != fa && !dep[to])
		{
			dfs(to,u,dp+1,en);
			now-=f[en];
		}
	}
	f[num] = now;
}

int dfs2(int u, int fa, int num){
	vis[u] = 1;
	LL now = a[u];
	for (auto v:E[u])
	{
		if (v.st != fa && !vis[v.st]){
			dfs2(v.st, u, v.nd);
			now -= f[v.nd];
		}
	}
	f[num] = now;
}

int gao(int flag)
{
	for (int i = 0; i <= m; i++)
		f[i] = 0, vis[i] = 0;
	int fd = 0;
	for (int i = 1; i <= m; i++)
		if ((dep[L[i]]&1) == (dep[R[i]]&1)){
			fd = i;
			f[i] = flag * NICO / 2;
			a[L[i]] -= f[i];
			a[R[i]] -= f[i];
			break;
		}
	if (fd == 0) return 0;
	dfs2(1, 0, 0);
	a[L[fd]] += f[fd];
	a[R[fd]] += f[fd];
	return f[0] == 0;
}

void print()
{
	puts("YES");
	for (int i=1;i<=m;i++)printf("%lld\n",f[i]);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	{	
		int x, y;
		scanf("%d%d", &x, &y);
		L[i] = x;
		R[i] = y;
		E[x].push_back(make_pair(y,i));
		E[y].push_back(make_pair(x,i));
	}
	dfs(1,0,1,0);
	if (!f[0] || gao(1) || gao(-1)){
		print();
	}
	else puts("NO");
}


