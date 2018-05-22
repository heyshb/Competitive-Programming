#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T,N;
int v[110][110];
vector<int>e[20010];
bool vis[20010]; 

int gao(int col,int x)
{
	return (col - 1) * N + x;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
			{
				scanf("%d",&v[i][j]);
				if (v[i][j] < 0) v[i][j] = -v[i][j] + N;
			}
		for (int i=1;i<=2*N*N;i++)e[i].clear();
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				e[gao(v[i][j],i)].push_back(gao(v[i][j],j));
	}
}
