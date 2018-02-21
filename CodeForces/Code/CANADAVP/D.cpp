#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct team
{
	LL t,w;
}T[300010];
bool cmp(team a,team b)
{
	return a.t>b.t;
};
int N;
priority_queue<LL,vector<LL>,greater<LL> > heap;
LL t0,w0;

int ans;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%I64d%I64d",&T[i].t,&T[i].w);
	}
	t0=T[1].t;
	w0=T[1].w;
	swap(T[1],T[N]);
	N--;
	sort(T+1,T+N+1,cmp);
	ans=0;
	for (int i=1;i<=N;i++)
	if (T[i].t>t0) 
	{
		ans++;//initial rank
		heap.push(T[i].t-T[i].w);
	}
	int now=t0,kill=0;
	LL delta;
	for (int i=ans+1;i<=N;i++)
	{
		if (T[i].t!=now)
		{
			if (t0-(now-T[i].t)<w0)
			{
				delta=t0-w0;
				break;
			}
			delta=
			now=T[i].t;
		}
		heap.push(T[i].t-T[i].w);
	}
	printf("%d\n",ans+1);
	
}
