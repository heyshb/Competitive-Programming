#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M,K;
int gov[1010],fa[1010],size[1010];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void uno(int x,int y)
{
	x = find(x);
	y = find(y);
	if (x==y) return;
	size[x] += size[y];
	fa[y] = x;
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for (int i=1;i<=N;i++)
	{
		fa[i] = i;
		size[i] = 1;
	}
	for (int i=1;i<=K;i++)scanf("%d",&gov[i]);
	for (int i=1;i<=M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		uno(x,y);
	}
	int freedom = N, maxv = -1, maxpos;
	LL ans = 0;
	for (int i=1;i<=K;i++)
	{
		int s = size[find(gov[i])];
		freedom -= s;
		if (s > maxv)
		{
			maxpos = i;
			maxv = s;
		}
	}
	size[find(gov[maxpos])]+=freedom;
	for (int i=1;i<=K;i++)
	{
		int s = size[find(gov[i])];
		ans+=LL(s)*LL(s-1)/2;
	}
	ans-=M;
	printf("%I64d\n",ans);
}
