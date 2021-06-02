#include <bits/stdc++.h>

using namespace std;

vector<int>e1[500010],e2[500010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
		{
			e1[i].clear();
			e2[i].clear();
		}
		int u,v;
		for (int i=1;i<N;i++)
		{
			scanf("%d%d",&u,&v);
			e1[u].push_back(v);
			e1[v].push_back(u);
		}
		for (int i=1;i<N;i++)
		{
			scanf("%d%d",&u,&v);
			e2[u].push_back(v);
			e2[v].push_back(u);
		}
	}
}
