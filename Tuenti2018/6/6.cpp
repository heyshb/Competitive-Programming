#include <bits/stdc++.h>

using namespace std;

typedef long long LL; 

int N;
struct seg
{
	LL L,R,P;
	friend bool operator < (seg a,seg b)
	{
		if (a.L == b.L)
			return a.R < b.R;
		return a.L < b.L;
	}
	friend bool operator == (seg a,seg b)
	{
		return a.L == b.L && a.R == b.R;
	}
}s[10010];
int cnt,M;
LL v[20010];
LL tr[20010];
int lowbit(int x){
	return x&-x;
}
LL getmax(int x){
	LL ret = 0;
	while(x)
	{
		ret = max(ret,tr[x]);
		x-=lowbit(x);
	}
	return ret;
}
void add(int x,LL y)
{
	while(x <= M)
	{
		tr[x] = max(tr[x],y);
		x += lowbit(x);
	}
}

LL search(LL x)
{
	return lower_bound(v+1,v+M+1,x) - v;	
}

int main()
{
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	int T,_=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		cnt = 0;
		for (int i=1;i<=N;i++)
		{
			LL L,S,P,X;
			scanf("%lld%lld%lld%lld",&X,&L,&S,&P);
			s[i].P = P;
			assert(X % S == 0 && L % S == 0);
			s[i].L = X / S;
			s[i].R = s[i].L + L / S; 
			//printf("%lld____%lld\n",s[i].L,s[i].R);
			v[++cnt] = s[i].L;
			v[++cnt] = s[i].R;
		}
		sort(v+1,v+cnt+1);
		v[0] = -1;
		M = 0;
		for (int i=1;i<=cnt;i++)	
		if (v[i] != v[i-1])
			v[++M] = v[i];
		for (int i=1;i<=N;i++)
		{
			s[i].L = search(s[i].L);
			s[i].R = search(s[i].R);	
		}	
		sort(s+1,s+N+1); 
		LL nowsum = 0,ans = 0;
		for (int i=0;i<=M;i++)tr[i] = 0;
		for (int i=1;i<=N;i++)
		{
			nowsum += s[i].P;
			if (i < N && s[i] == s[i+1])continue; 
			LL mx = nowsum + getmax(s[i].L - 1);
			ans = max(ans,mx);
			add(s[i].R,mx);
			nowsum = 0;
		}
		printf("Case #%d: %lld\n",++_,ans);
	}
}
