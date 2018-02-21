#include <bits/stdc++.h>

using namespace std;

int N,Q;
double d[110][110];
int E[110],S[110];
double f[110];
double sum[110];
vector<int>e[110];
vector<double>len[110];
double dis[110][110];

int main()
{
	freopen("Cl.in","r",stdin);
	freopen("Cl.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d%d",&N,&Q);
		for (int i=1;i<=N;i++)scanf("%d%d",&E[i],&S[i]);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)d[i][j] = 1e15;
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
			{
				int v;
				scanf("%d",&v);
				if (v!=-1)
					d[i][j] = v;
			}
		for (int i=1;i<=N;i++)d[i][i] = 0;
		for (int k=1;k<=N;k++)
			for (int i=1;i<=N;i++)
				for (int j=1;j<=N;j++)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		for (int i=1;i<=N;i++)e[i].clear(),len[i].clear();
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
			if (d[i][j] < E[i] + 1e-5)
			{
				e[i].push_back(j);
				len[i].push_back(d[i][j]/S[i]);
			}
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
			if (i==j)
				dis[i][j] = 0;
			else
				dis[i][j] = 1e15;
		for (int i=1;i<=N;i++)
			for (int j=0;j<e[i].size();j++)
			dis[i][e[i][j]] = len[i][j];
		for (int k=1;k<=N;k++)
			for (int i=1;i<=N;i++)
				for (int j=1;j<=N;j++)
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
		vector<double>ans;
		ans.clear();
		while(Q--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			ans.push_back(dis[u][v]);
		}
		printf("Case #%d:",_);
		for (auto t:ans) printf(" %.10lf",t);
		puts("");
	}
}
