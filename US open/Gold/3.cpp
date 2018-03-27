#include <bits/stdc++.h>

using namespace std;

struct cow
{
	int w,t;
}c[300];

bool cmp(cow a,cow b)
{
	//a.t/a.w < b.t/b.w
	return a.t*b.w < b.t*a.w;
}

int N,W;
typedef long long LL;

int main()
{
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	scanf("%d%d",&N,&W);
	for (int i=1;i<=N;i++)scanf("%d%d",&c[i].w,&c[i].t);
	sort(c+1,c+N+1,cmp);
	LL sw = 0,st = 0;	
	for (int i=N;i>=1;i--)
	{
		sw += c[i].w;
		st += c[i].t;
		if (sw >= W)
		{
			printf("%lld\n",st*1000/sw);
			break;
		}
	}
}
