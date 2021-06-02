#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int l,r,w;
}e[200010];
int N,M;
bool cmp(edge a,edge b){return a.w>b.w;}
int fa[200010],sum[200010];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++)scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].w);
	sort(e+1,e+M+1,cmp);
	int ans = 0;
	for (int i=1;i<=N;i++)fa[i] = i, sum[i] = 0;
	for (int i=1;i<=M;i++)
	{
		int u = e[i].l, v = e[i].r;
		if (find(u) != find(v))
		{
			if (sum[find(u)] + sum[find(v)] <= 1)
			{
				sum[find(u)] += sum[find(v)];
				fa[find(v)] = find(u);
				ans += e[i].w;
			}
		}
		else
		{
			if (sum[find(u)] == 0)
			{
				sum[find(u)]++;
				ans += e[i].w;
			}
		}
	}
	printf("%d\n",ans);
}
