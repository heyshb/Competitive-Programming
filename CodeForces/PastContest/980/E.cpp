#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int D = 20;
int N,K;
vector<int>e[1000010];
int anc[1000010][D + 1],dep[1000010];
bool choose[1000010];

int lca(int x,int y)
{
	if (dep[x] < dep[y]) swap(x,y);
	int delta = dep[x] - dep[y];
	for (int i=0;i<=D;i++)
	if (delta & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i=D;i>=0;i--)
	if (anc[x][i] != anc[y][i])
	{
		x = anc[x][i];
		y = anc[y][i];
	}
	return anc[x][0];
}

void dfs(int x,int fa)
{
	anc[x][0] = fa;
	dep[x] = dep[fa] + 1;
	for (int i=1;i<=D;i++)anc[x][i] = anc[anc[x][i-1]][i-1];
	for (auto t:e[x])
	if (t != fa) dfs(t,x);
}

int main()
{
	//freopen("2.in","r",stdin);
	scanf("%d%d",&N,&K);
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	K = N - K;
	dfs(1,0);
	choose[N] = true;
	int minp = N;
	int done = 1;
	for (int i=N-1;i>=1;i--)
	{
		if (choose[i]) continue;
		int LCA = lca(i,minp);
		if (!choose[LCA])
		{
			int delta = dep[minp] - dep[LCA] + dep[i] - dep[LCA];
			if (done + delta > K) continue;
			done += delta;
			for (int j=minp;j!=LCA;j=anc[j][0])choose[j] = true;
			for (int j=i;j!=LCA;j=anc[j][0])choose[j] = true;
			choose[LCA] = true;
			minp = LCA;
		}
		else
		{
			assert(LCA == minp);
			int x = i;
			for (int j=D;j>=0;j--)
			{
				if (dep[anc[x][j]] < dep[minp]) continue;
				if (choose[anc[x][j]]) continue;
				x = anc[x][j];
			}
			x = anc[x][0];
			int delta = dep[i] - dep[x];
			if (done + delta > K) continue;
			done += delta;
			for (int j=i;j!=x;j=anc[j][0])choose[j] = true;
		}
	}
	vector<int>ans;
	for (int i=1;i<=N;i++)
	if (!choose[i]) ans.push_back(i);
	assert(ans.size() == N - K); 
	for (int i=0;i<ans.size();i++)printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
}
