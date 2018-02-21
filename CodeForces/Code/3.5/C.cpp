#include <bits/stdc++.h>

using namespace std;

int N,M,K;
vector<int>e[200010];
vector<int>res;
bool vis[200010];

void dfs(int x)
{
	vis[x] = true;
	res.push_back(x);
	for (int i=0;i<e[x].size();i++)
	{
		int y = e[x][i];
		if (vis[y]) continue;
		//printf("%d---->%d\n",x,y);
		dfs(y);
		res.push_back(x);
	}
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for (int i=1;i<=M;i++)
	{
		int X,Y;
		scanf("%d%d",&X,&Y);
		e[X].push_back(Y);
		e[Y].push_back(X);
	}
	memset(vis,false,sizeof(vis));
	dfs(1);
	
	int sum = res.size();
	assert(sum == 2*N-1);
	int e = (2*N+K-1)/K;
	for (int i=0;i<K;i++)
	{
		int L = i*e, R = min((i+1)*e,sum);
		if (L>=R) L = R-1;
		printf("%d",R-L);
		for (int j=L;j<R;j++)printf(" %d",res[j]);
		puts("");
	}
}
