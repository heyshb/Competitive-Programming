#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
int g[110][110];
int mi[2][110];
pair<int,int>ans[1000010];
bool vis[110][110];
queue<pair<int,int> >q;

int main()
{
	scanf("%d%d",&N,&M);
	int minv = 10000;
	for (int i=1;i<=N;i++)mi[0][i] = 10000;
	for (int i=1;i<=M;i++)mi[1][i] = 10000;
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			scanf("%d",&g[i][j]);
			minv = min(minv,g[i][j]);
		}
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		g[i][j] -= minv;
	int K = 0;
	if (N <= M)
	{
		K = N;
		for (int i=1;i<=N;i++)
			ans.push_back(make_pair(0,i));
	}
	else
	{
		K = M;
		for (int i=1;i<=M;i++)
			ans.push_back(make_pair(1,i));
	}
	
	bool ok = true;
	int done = 0;
	mesmet(vis,false,sizeof(vis));
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			if (!g[i][j])
			{
				q.push(make_pair(i,j));
				vis[i][j] = true;
				done++;
			}
			mi[0][i] = min(mi[0][i],g[i][j]);
			mi[1][j] = min(mi[1][j],g[i][j]);
		}
	while(!q.empty())
	{
		auto t = q.front();
		int x = t.first, y = t.second;
		q.pop();
		for (int i=1;i<=M;i++)
		if (g[x][i])
		{
			if (g[x][i] != mi[1][i]) return 0*puts("-1");
			for (int j=1;j<=g[x][i];j++)
				ans.push_back(make_pair(1,i));
			for (int j=1;j<=N;j++)
			{
				g[j][i] -= g[x][i];
				mi[0][j] = min(mi[0][j],g[j][i]);
				if (g[j][i] == 0)
					q.push(make_pair(j,i));
			}
			mi[1][i] = 0;
			q.push(make_pair(x,i));
		}
	}
	for (auto t:ans)
	{
		if (t.first)
			printf("col %d\n",t.second);
		else
			printf("row %d\n",t.first);
	}
	return 0;
		
}
