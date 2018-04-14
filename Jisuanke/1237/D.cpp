#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
vector<int>e[100010];
int d[100010],L[100010],R[100010];
bool flag[100010];
int bd; 

int main()
{
	scanf("%d%d",&N,&M);
	bd = int(sqrt(M) + 1);
	for (int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if (u > v) swap(u,v);
		e[u].push_back(v);
		e[v].push_back(u);
		L[i] = u;
		R[i] = v;
		d[u]++;
		d[v]++;
	}
	memset(flag,false,sizeof(flag));
	for (int i=1;i<=M;i++)
	if (d[L[i]] <= bd && d[R[i]] <= bd)
}

