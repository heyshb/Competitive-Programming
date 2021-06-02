#include <bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;

typedef long long LL;

const int MAXNODE = 20000010;
struct Node
{
	int ls,rs;
	LL hsh;	
}T[MAXNODE];

const LL seed = 252;
const LL MOD = 1000000007;
LL po[100010];
int cnt,N;
int root[100010];
int v[100010];

void maintain(int x,int l,int r)
{
	T[x].hsh = (T[T[x].rs].hsh + T[T[x].ls].hsh * po[r - mid] ) % MOD;
}

int modify(int x,int l,int r,int pos,int v)
{
	int now = ++cnt;
	if (l == r)
	{
		T[now].hsh = v;
		return now;
	}
	else
	{
		if (pos <= mid)
		{
			T[now].rs = T[x].rs;
			T[now].ls = modify(T[x].ls,l,mid,pos,v);
		}
		else
		{
			T[now].ls = T[x].ls;
			T[now].rs = modify(T[x].rs,mid+1,r,pos,v);
		}
		maintain(now,l,r);
		return now;
	}
}

int getpos(int x,int l,int r,int pos)
{
	if (l == r)
		return T[x].hsh;
	else if (pos <= mid)
		return getpos(T[x].ls,l,mid,pos);
	else
		return getpos(T[x].rs,mid+1,r,pos);
}

int lcp(int x,int y,int l,int r)
{
	//printf("%d %d %d %d %lld %lld\n",x,y,l,r,T[x].hsh,T[y].hsh);
	if (l == r) return (T[x].hsh == T[y].hsh);
	if (T[T[x].ls].hsh == T[T[y].ls].hsh)
		return (mid - l + 1) + lcp(T[x].rs,T[y].rs,mid+1,r);
	else
		return lcp(T[x].ls,T[y].ls,l,mid); 
}

int build(int l,int r)
{
	int now = ++cnt;
	T[now].hsh = 0;
	T[now].ls = T[now].rs = 0;
	if (l == r) return now;
	T[now].ls = build(l,mid);
	T[now].rs = build(mid+1,r);
	return now;
}

struct myComp
{ 
	bool operator() (const int &x,const int &y)//str[x] < str[y]
	{
		int len = lcp(x,y,1,N);
		if (len == N) return false;
		return getpos(x,1,N,len+1) < getpos(y,1,N,len+1);
	}
};

multiset<int,myComp>st;

int main()
{
	freopen("WALKBT.in","r",stdin);
	po[0] = 1;
	for (int i=1;i<=100000;i++)po[i] = po[i-1] * seed % MOD;
	int Cases;
	scanf("%d",&Cases);
	while(Cases--)
	{
		int Q;
		scanf("%d%d",&N,&Q); 
		if (cnt)
		{
			for (int i=1;i<=cnt;i++)T[i].ls = T[i].rs = T[i].hsh = 0;
			cnt = 0;
		}
		for (int i=1;i<=N;i++)v[i] = 0;
		st.clear();
		root[0] = build(1,N);
		int strcnt = 0;
		LL ans = 1;
		char op[2];
		int pos,ll;
		while(Q--)
		{
			//puts("-------");
			scanf("%s",op);
			if (op[0] == '!')
			{
				scanf("%d",&pos);
				pos = N - pos;
				if (v[pos] == 0)
				{
					v[pos] = 1;
					ll = pos;
				}
				else
				{
					v[pos] = 0;
					ll = pos - 1;
					while(ll > 0)
					{
						v[ll] ^= 1;
						if (v[ll] == 1) break;
						ll--;
					}
					if (ll == 0) ll = 1;
				}
				root[++strcnt] = modify(root[strcnt-1],1,N,pos,v[pos]);
				for (int i=pos-1;i>=ll;i--)
					root[strcnt] = modify(root[strcnt],1,N,i,v[i]);
				st.insert(root[strcnt]);
				auto it = st.find(root[strcnt]);
				int maxlcp = 0;
				if (it != st.begin())
				{
					auto pre = prev(it);
					maxlcp = lcp((*it),(*pre),1,N);
				}
				auto nxt = next(it);
				if (nxt != st.end())
				{
					maxlcp = max(maxlcp,lcp((*it),(*nxt),1,N));
				}
				//printf("%d\n",maxlcp);
				ans += LL(N - maxlcp);
			}
			else
			{
				printf("%lld\n",ans);
			}
		}
	}
}
