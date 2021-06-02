#include <bits/stdc++.h>

using namespace std;

struct query
{
	int type,C,ans;
}q[100010];

int N,M,T;
vector<int>e[100010];
int col[100010];
int fa[100010];

vector<int>tmp;

void dfs(int x,int f,int now)
{
	if (now) tmp.push_back(x);
	for (auto t:e[x])
	if (t != f)
		dfs(t,x,now|col[t]);
}


int query(int x)
{
	tmp.clear();
	if (col[x]) return (N>=2?N-1:-1);
	dfs(x,0,0);
	sort(tmp.begin(),tmp.end());
	if (tmp.size() < 2) return -1;
	return tmp[tmp.size()-2];
}

int main()
{
	freopen("LVGFT.in","r",stdin);
	freopen("brute.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for (int i=1;i<=N;i++)e[i].clear(),col[i] = 0;
		for (int i=1;i<N;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int i=1;i<=M;i++)
		{
			scanf("%d%d",&q[i].type,&q[i].C);
			if (q[i].type == 1)
				col[q[i].C] = 1;
			else
				printf("%d\n",query(q[i].C));
		}
	}
}
