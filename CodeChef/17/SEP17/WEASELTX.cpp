#include <bits/stdc++.h>
#define mid ((l+r) >> 1)
using namespace std;

const int MAXN = 300010;
const int MAXDEP = 18;
typedef long long LL;
int N,Q;
LL v[MAXN],v0[MAXN];
int dep[MAXN];
struct Node
{
	LL sum;
	vector<LL>v; 
}T[MAXN*4];

vector<int>e[MAXN];

void dfs(int x,int fa,int d)
{
	dep[x] = d;
	for (auto t:e[x])
	if (t != fa) dfs(t,x,d+1);
}

void build(int x,int l,int r)//[l,r)
{
	//printf("build %d %d %d\n",x,l,r);
	T[x].sum = 0;
	for (auto t:T[x].v) T[x].sum ^= t;
	if (l == r - 1) return;
	for (int i=l;i<mid;i++)
	{
		T[x*2].v.push_back(T[x].v[i-l]);
		T[x*2+1].v.push_back(T[x].v[i-l] ^ T[x].v[i-l+(r-l)/2]);
	}
	build(x*2,l,mid);
	build(x*2+1,mid,r);
}

int main()
{
	//freopen("XOR.in","r",stdin);
	int N,Q;
	scanf("%d%d",&N,&Q);
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=0;i<N;i++)scanf("%lld",&v0[i]);
	dfs(0,-1,0);
	for (int i=0;i<N;i++)v[dep[i]] ^= v0[i];
	int sz = 1;
	while(sz < N) sz<<=1;
	for (int i=0;i<sz;i++)T[1].v.push_back(v[i]);
	build(1,0,sz);
	while(Q--)
	{
		LL t;
		scanf("%lld",&t);
		if (t == 0) 
		{
			printf("%lld\n",v0[0]);
			continue;
		}
		t--;
		t %= sz;
		int sizesqr = sz, now = 1;
		while(sizesqr > 1)
		{
			if (t >= sizesqr/2)
			{
				t -= sizesqr/2;
				now = now * 2;
			}
			else
			{
				now = now * 2 + 1;
			}
			sizesqr /= 2;
		}
		printf("%lld\n",T[now].sum);
	}
}
