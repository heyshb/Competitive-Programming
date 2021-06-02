#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct ticket
{
	int d,f,t;
	LL c;
}T[100010];
bool cmp(ticket A,ticket B)
{
	if (A.d == B.d) return A.c > B.c;
	return A.d > B.d;
}
bool cmp2(ticket A,ticket B)
{
	if (A.d == B.d) return A.c > B.c;
	return A.d < B.d;
}
int N,M,K;
vector<ticket>arrive[100010],leave[100010];
int ta[100010],la[100010];
const LL INF = 1e12;
LL d[100010];

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	ticket tmp;
	for (int i=1;i<=M;i++)
		scanf("%d%d%d%lld",&T[i].d,&T[i].f,&T[i].t,&T[i].c);
	sort(T+1,T+M+1,cmp);
	for (int i=1;i<=M;i++)//f --> t   day down
	{
		if (T[i].t == 0)
		{
			int fr = T[i].f;
			while(!arrive[fr].empty() && arrive[fr].back().c >= T[i].c)
				arrive[fr].pop_back();
			arrive[fr].push_back(T[i]);
		}
	}
	sort(T+1,T+M+1,cmp2);
	for (int i=1;i<=M;i++)// day up
	{
		if (T[i].f == 0)
		{
			int to = T[i].t;
			while(!leave[to].empty() && leave[to].back().c >= T[i].c)
				leave[to].pop_back();
			leave[to].push_back(T[i]);
		}
	}
	int minarrive = 1e9;
	LL nowans = 0;
	d[0] = INF;
	if (ans == INF) puts("-1");
	else printf("%lld\n",ans);
}
