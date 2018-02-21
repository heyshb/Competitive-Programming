#include <bits/stdc++.h>

using namespace std;

int N; 
vector<int>e[200010];
int d[200010],f[200010];

void dfs(int x,int fa)
{
	for (auto t:e[x])
	if (t != fa)
	{
		d[t] = d[x] + 1;
		dfs(t,x);	
	}	
}

bool check(int x)
{
	d[1] = 0;
	dfs(1,-1);
	int md = -1,mn; 
	for (int i=1;i<=N;i++)
	if (d[i] > md)
	{
		mn = i;
		md = d[i];
	}
	
}

void check2(int x)
{
	
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int L = 0,R = N; 
	while(L < R - 1)
	{
		int mid = (L + R) / 2;
		if (check(mid))
			R = mid;
		else
			L = mid;
	}
	check2(R);
}
