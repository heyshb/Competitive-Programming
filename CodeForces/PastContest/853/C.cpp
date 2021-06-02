#include <bits/stdc++.h>

using namespace std;

struct query
{
	int l,d,r,u;
	int id;
}Q[200010];
typedef long long LL;

int N,q;
int lowbit(int x){return x&-x;}
LL getsum(LL *tr,int x){int s=0;while(x){s+=tr[x];x-=lowbit(x);}return s;}
void add(LL *tr,int x,int y){while(x<=N){tr[x]+=y;x+=lowbit(x);}}
int p[200010];
int s1[200010],s2[200010];
LL C2(LL N){return N * (N-1) / 2;}
LL tr[500010];

struct event
{
	int type,id;
	int x,y;
	int d,u;
};
vector<event>e;
bool cmp1(event a,event b){if (a.x==b.x) return a.y<b.y;return a.x < b.x;}
bool cmp2(event a,event b){if (a.x==b.x) return a.y<b.y;return a.x > b.x;}
LL ans[200010];

int main()
{
	scanf("%d%d",&N,&q);
	for (int i=1;i<=N;i++)scanf("%d",&p[i]);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&Q[i].l,&Q[i].d,&Q[i].r,&Q[i].u);
		ans[i] = C2(N);
		ans[i] -= C2(Q[i].l-1);
		ans[i] -= C2(Q[i].d-1);
		ans[i] -= C2(N-Q[i].r);
		ans[i] -= C2(N-Q[i].u);
	}		
	e.clear();
	for (int i=1;i<=q;i++)
	{
		e.push_back((event){1,i,Q[i].l,0,Q[i].d,Q[i].u});
	}
	memset(tr,0,sizeof(tr));
	for (int i=1;i<=N;i++)
		e.push_back((event){2,0,i,p[i],0,0});
	sort(e.begin(),e.end(),cmp1);
	for (auto t:e)
	if (t.type == 1)
	{
		ans[t.id] += C2(getsum(tr,N) - getsum(tr,t.u));
		ans[t.id] += C2(getsum(tr,t.d-1));
	}
	else
	{
		add(tr,t.y,1);
	}
	
	
	e.clear();
	for (int i=1;i<=q;i++)
	{
		e.push_back((event){1,i,Q[i].r,0,Q[i].d,Q[i].u});
	}
	memset(tr,0,sizeof(tr));
	for (int i=1;i<=N;i++)
		e.push_back((event){2,0,i,p[i],0,0});
	sort(e.begin(),e.end(),cmp2);
	
	for (auto t:e)
	if (t.type == 1)
	{
		ans[t.id] += C2(getsum(tr,N) - getsum(tr,t.u));
		ans[t.id] += C2(getsum(tr,t.d-1));
	}
	else
	{
		add(tr,t.y,1);
	}
	
	for (int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}

