#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int>e[100010];
int col[100010];
int maxpos[100010];

int solve()
{
	scanf("%d%d",&N,&M);
	for (int i=0;i<=N;i++)e[i].clear();
	bool ok = true;
	for (int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if (u >= v) ok = false;
		e[v].push_back(u);
	}
	if (!ok) return puts("-1");
	for (int i=1;i<=N;i++)col[i] = 0;
	int cnt = 0;
	for (int i=1;i<=N;i++)sort(e[i].begin(),e[i].end());
	for (int i=1;i<=N;i++)maxpos[i] = -1;
	for (int i=1;i<=N;i++)
	{
		//printf("%d\n",i);
		if (!e[i].size()) return puts("-1");
		int sz = e[i].size();
		for (int j=0;j<sz-1;j++)
		{
			//printf("check %d:%d %d\n",i,e[i][j],e[i][j+1]); 
			if (e[i][j] != e[i][j+1]-1) return puts("-1");
		} 
		//puts("done");
		if (e[i][sz-1] != i-1) return puts("-1");
		if (e[i][0] == 0)
			col[i] = ++cnt;
		else
			col[i] = col[e[i][0]];
		if (maxpos[col[i]] != -1 && maxpos[col[i]] > e[i][0]) return puts("-1");
		maxpos[col[i]] = i;
	}
	for (int i=1;i<=N;i++)printf("%d%c",col[i],i==N?'\n':' ');
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
}
