#include <bits/stdc++.h>

using namespace std;

struct event
{
	int type;//1 addedge 2 query
	int u,v;
	int K;
	int num;
};
vector<event>ev;

bool cmp(event a,event b)
{
	if (a.K == b.K) return a.type < b.type;
	return a.K < b.K;
}

int N,M;
int T[100010];
vector<int> e[100010];
int lowbit(int x){return x&-x;}
void add(int x,int K){while(x<=N+5){T[x]^=K;x+=lowbit(x);}}
int get(int x){x++;int s=0;while(x){s^=T[x];x-=lowbit(x);}return s;}
int addr(int l,int r,int K){l++;r++;add(l,K);add(r+1,K);}
int getr(int x){return get(x)^get(x-1);}
int fa[100010];
int dfn[100010],L[100010],R[100010],ans[100010];
const int maxdep = 17;
int tmm,anc[100010][maxdep],dep[100010];

void dfs(int x,int f)
{
	dfn[L[x] = ++tmm] = x;
	fa[x] = f;
	anc[x][0] = f;
	for (int i=1;i<maxdep;i++)
		anc[x][i] = anc[anc[x][i-1]][i-1];
	dep[x] = dep[f] + 1;
	for (auto t:e[x])
	if (t!=f)
		dfs(t,x);
	R[x] = tmm;
}

int lca(int x,int y)
{
	if (dep[x] < dep[y]) swap(x,y);
	int delta = dep[x] - dep[y];
	for (int i=0;i<delta;i++)
		if (delta & (1<<i))
		x = anc[x][i];
	if (x==y) return x;
	for (int i=maxdep-1;i>=0;i--)
	if (anc[x][i] != anc[y][i])
	{
		x = anc[x][i];
		y = anc[y][i];
	}
	return fa[x];
}

int main()
{
	int TTT;
	scanf("%d",&TTT);
	while(TTT--)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)e[i].clear();
		int u,v,K;
		ev.clear();
		for (int i=1;i<N;i++)
		{
			scanf("%d%d%d",&u,&v,&K);
			e[u].push_back(v);
			e[v].push_back(u);
			ev.push_back((event){1,u,v,K,i});
		}
		tmm = 0;
		dep[1] = 1;
		dfs(1,0);
		scanf("%d",&M);
		for (int i=1;i<=M;i++)
		{
			scanf("%d%d%d",&u,&v,&K);
			ev.push_back((event){2,u,v,K,i});
		}
		sort(ev.begin(),ev.end(),cmp);
		memset(T,0,sizeof(T)); 
		for (auto EE:ev)
		{
			if (EE.type == 1)
			{
				int so;
				if (EE.v == fa[EE.u])
					so = EE.u;
				else
					so = EE.v;
				addr(L[so],R[so],EE.K);
			}
			else
			{
				int w = lca(EE.u,EE.v);
				ans[EE.num] = get(L[EE.u]) ^ get(L[EE.v]);//getr(L[EE.u]) ^ getr(L[EE.v]);
			}
		}
		for (int i=1;i<=M;i++)printf("%d\n",ans[i]);
	}
}

/*
1
5
1 2 1
2 3 2
2 4 5
3 5 10
6
5 4 5
5 4 10
5 4 1
1 2 1
4 1 10
1 5 8

*/
