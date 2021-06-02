#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
vector<int>e[1000010];
int d[1000010]; 
int l[1000010],r[1000010];
int fa[1000010];
vector<int>R;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)fa[i] = i;
	for (int i=1;i<=M;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		if (l[i] == r[i])
		{
			R.push_back(l[i]);
			continue;
		}
		e[l[i]].push_back(r[i]);
		e[r[i]].push_back(l[i]);
		int LL,RR;
		LL = find(l[i]);
		RR = find(r[i]);
		if (LL == RR) continue;
		fa[LL] = RR;
	}
	int root = find(l[1]);
	for (int i=2;i<=M;i++)
	if (find(l[i]) != root || find(r[i]) != root)
	{
		puts("0");
		return 0;
	}
	LL ans = 0;
	for (int i=1;i<=N;i++)
	{
		LL d = e[i].size();
		ans+=d*(d-1)/2;
	}
	LL sr = R.size();
	ans+= sr*(M-sr) + sr*(sr-1)/2;
	printf("%I64d\n",ans);
}
