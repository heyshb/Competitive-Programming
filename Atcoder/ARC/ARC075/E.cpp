#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
LL K;
LL a[200010],s[200010];

const LL INF = 1e15;
struct seg
{
	int ls,rs;
	int sum;
}T[20000010];
int cnt;

void ins(int x,LL l,LL r,LL v)
{
	//printf("%lld %lld\n",l,r);
	T[x].sum++;
	if (l == r) return;
	LL mid = (l+r) >> 1;
	if (v <= mid)
	{
		if (!T[x].ls)
			T[x].ls = ++cnt;
		ins(T[x].ls,l,mid,v);
	}
	else
	{
		if (!T[x].rs)
			T[x].rs = ++cnt;
		ins(T[x].rs,mid+1,r,v);
	}
}

LL query(int x,LL l,LL r,LL v)
{
	if (l == r) return T[x].sum;
	LL mid = (l + r) >> 1;
	if (v <= mid)
		return query(T[x].ls,l,mid,v);
	else
		return T[T[x].ls].sum + query(T[x].rs,mid+1,r,v);
}

int main()
{
	scanf("%d%lld",&N,&K);
	s[0] = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%lld",&a[i]);
		a[i] -= K;
		s[i] = s[i-1] + a[i];
	}
	cnt = 1;
	T[1].ls = T[1].rs = T[1].sum = 0;
	ins(1,-INF,INF,0);
	LL ans = 0;
	for (int i=1;i<=N;i++)
	{
		ans += query(1,-INF,INF,s[i]);
		//printf("%lld\n",ans);
		ins(1,-INF,INF,s[i]);
	}
	printf("%lld\n",ans);
}
