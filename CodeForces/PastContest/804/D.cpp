#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M,Q; 
int fa[100010];
vector<int>e[100010];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int size[100010];
bool vis[100010];
vector<int>nowcom;
queue<int>q;
int d[100010],D[100010];
int far[100010];
int bl[100010];
int num[100010];
double ans[400][100010];
vector<int>com[100010];
vector<LL>dis[100010],sum[100010];

int bfs(int x)
{
	nowcom.clear();
	d[x] = 0;
	vis[x] = true;
	q.push(x);
	while(!q.empty())
	{
		int now = q.front();
		nowcom.push_back(now);
		q.pop();
		for (auto t:e[now])
		if (!vis[t])
		{
			vis[t] = true;
			d[t] = d[now] + 1;
			q.push(t);
		}
	}
	int maxd = -1, res;
	for (auto t:nowcom)
		if (d[t] > maxd)
		{
			maxd = d[t];
			res = t;
		}
	return res;
}

int main()
{
	int blk;
	scanf("%d%d%d",&N,&M,&Q); 
	blk = int(sqrt(N) + 1.0);
	for (int i=1;i<=N;i++)fa[i]=i;
	for (int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		u = find(u);
		v = find(v);
		if (u!=v)
			fa[u] = v;
	}
	memset(size,0,sizeof(size));
	memset(vis,false,sizeof(vis));
	int cnt = 0;
	for (int i=1;i<=N;i++)
	if (!vis[i])
	{
		cnt++;
		int u = bfs(i);
		for (auto t:nowcom) vis[t] = false;
		size[cnt] = nowcom.size();
		int v = bfs(u);
		D[cnt] = d[v];
		for (auto t:nowcom) far[t] = d[t],vis[t] = false;
		bfs(v);
		for (auto t:nowcom) far[t] = max(far[t],d[t]);
		for (auto t:nowcom)
		{
			com[cnt].push_back(t);
			dis[cnt].push_back(far[t]);
			bl[t] = cnt;
		}
		sort(dis[cnt].begin(),dis[cnt].end());
		sum[cnt][0] = dis[cnt][0];
		for (int j=1;j<dis[cnt].size();j++)
			sum[cnt][j] = sum[cnt][j-1] + dis[cnt][j];
	}
	for (int i=1;i<=cnt;i++)
	if (size[i] > blk)
	{
	}
	while(Q--)
	{
		int u,v,U,V;
		scanf("%d%d",&u,&v);
		U = bl[u];
		V = bl[v];
		if (U == V)
		{
			puts("-1");
			continue;
		}
		if (size[U] < size[V]) {swap(U,V);swap(u,v);}
		if (size[U] > blk)
			printf("%.8lf\n",ans[num[bl[u]]][bl[v]]);
		else
			
	}
}
