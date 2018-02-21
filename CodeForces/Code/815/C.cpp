#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL INF = 1e15;
LL f[5010][5010][2];
LL d[5010][5010][2];
vector<int>e[5010];
priority_queue<pair<LL,int> >heap;
int N;
int size[5010]; 
int node[5010];
LL b,c[5010],d[5010];

void dfs(int x)
{
	size[x] = 1;
	for (auto t:e[x]) 
	{
		dfs(t);
		size[x] += size[t];
	}
	f[x][1][1] = d[i];
	f[x][0][0] = 0;
	heap.clear();
	
	for (auto t:e[x])
	{
		node[t] = 1;
	}
	
	
	for (int i=1;i<=size[x];i++)
	{
		d[x][i][1] = min(f[x][i][0],f[x][i][1]) - min(f[x][i-1][0],f[x][i-1][1]);
		d[x][i][0] = f[x][i][0] - f[x][i-1][0];
	}
}

int main()
{
	scanf("%d%I64d",&N,&b);
	for (int i=1;i<=N;i++)
		for (int j=0;j<=N;j++)
		f[i][j][0] = f[i][j][1] = INF;
	for (int i=1;i<=N;i++)
	{
		scanf("%lld%lld",&c[i],&d[i]);
		d[i] = c[i] - d[i];
	}
	for (int i=2;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		e[tmp].push_back(i);
	}
	dfs(1);
}
