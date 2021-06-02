#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

struct edge
{
	int L,R;
}e[5010];

int M,N;
int fa[10010];
int find(int x){return x==fa[x]?x:fa[x] = find(fa[x]);}
int v[10010],cnt;
bool vis[10010];
vector<pair<int,int> >p[10010];
vector<pair<int,int> >ee[10010];
int pre[10010],from[10010];
int dfn[10010],low[10010];
int idx;
int bl[10010];
int stk[10010],top;
int tot,ans;
int miR[10010];

void dfs(int x,int f,int nu)
{
	dfn[x] = low[x] = ++idx,stk[++top] = x;
	for (auto t:ee[x])
	{
		//printf("%d %d %d %d %d\n",x,f,nu,t.first,t.second);
		if (t.first != f || (t.first == f && t.second != nu))
		{
			//printf("see %d %d\n",x,t.first);
			if (!dfn[t.first])
				dfs(t.first,x,t.second), low[x] = min(low[x],low[t.first]);
			else
				low[x] = min(low[x],dfn[t.first]);
		}
	}
				
	//printf("%d %d %d\n",x,dfn[x],low[x]);
		
	if (low[x] == dfn[x])
	{
		++tot;
		do
		{
			bl[stk[top]] = tot;
		}while(stk[top--] != x);
	}
}

int main()
{
	//freopen("LKYEDGE.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tot = 0;
		scanf("%d",&M);
		cnt = 0;
		for (int i=1;i<=M;i++)
		{
			scanf("%d%d",&e[i].L,&e[i].R);
			v[++cnt] = e[i].L;
			v[++cnt] = e[i].R;
		}
		sort(v+1,v+cnt+1);
		N = 0;
		for (int i=1;i<=cnt;i++)
		if (v[i] != v[i-1])
			v[++N] = v[i];
		for (int i=1;i<=M;i++)
		{
			e[i].L = lower_bound(v+1,v+N+1,e[i].L) - v;
			e[i].R = lower_bound(v+1,v+N+1,e[i].R) - v;
			p[i].clear();
		}
		for (int i=1;i<=N;i++)fa[i] = i,vis[i] = false;
		for (int L=1;L<=M;L++)
		{
			int u = e[L].L, v = e[L].R;
			int R = M + 1;
			for (int i=L+1;i<=M;i++)
			{
				if (find(e[i].L) != find(e[i].R))
					fa[find(e[i].L)] = find(e[i].R);
				if (find(u) == find(v))
				{
					R = i;
					break;
				}
			}
			//printf("%d %d\n",L,R);
			if (R <= M)
			{
				for (int i=L;i<=R;i++)
				{
					ee[e[i].L].push_back(mp(e[i].R,i));
					ee[e[i].R].push_back(mp(e[i].L,i));
					//printf("add %d %d %d\n",e[i].L,e[i].R,i);
					dfn[e[i].L] = dfn[e[i].R] = 0;
				}
				idx = 0;
				dfs(u,0,0);
				//printf("u=%d v=%d\n",u,v);
				//for (int i=1;i<=N;i++)printf("%d %d\n",i,bl[i]);
				for (int i=L;i<=R;i++)
				{
					if (bl[e[i].L] == bl[u] && bl[e[i].R] == bl[u])
					{
						//printf("push %d %d %d\n",i,L,R);
						p[i].push_back(mp(L,R));
					}
				}
			}
			
			R = min(R,M);
			for (int i=L+1;i<=R;i++)
			{
				ee[e[i].L].clear();
				ee[e[i].R].clear();
				fa[e[i].L] = e[i].L;
				fa[e[i].R] = e[i].R;
				vis[e[i].L] = false;
				vis[e[i].R] = false;
				bl[e[i].L] = bl[e[i].R] = 0;
			}
		}
		for (int i=1;i<=M;i++)
		{
			int ans = 0;
			for (int j=1;j<=M;j++)miR[j] = M+1;
			for (auto t:p[i])
				miR[t.first] = min(miR[t.first],t.second);
			for (int j=M-1;j>=1;j--)
				miR[j] = min(miR[j],miR[j+1]);
			for (int j=i;j>=1;j--)
				ans += M - miR[j] + 1;
			printf("%d",ans);
			if (i==M) puts("");else printf(" ");
		}
	}
}
