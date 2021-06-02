#include <bits/stdc++.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long LL;

bool choose[300010];
int N,M;
vector<pair<int,int> >e[300010]; 
int col[300010];
int sum[300010];
bool vis[300010];
vector<int>p1,p2;

void dfs(int x,int fa)
{
	sum[x] = (col[x] == 1);
	for (auto t:e[x])
	if (t.X != fa && !vis[t.X])
	{
		vis[t.X] = true;
		dfs(t.X,x);
		if (sum[t.X]) choose[t.Y] = true;
		sum[x] ^= sum[t.X];
	}
}

vector<int>ans;

int main()
{
	p1.clear();
	p2.clear();
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&col[i]);
		if (col[i] == 1) p1.pb(i);
		if (col[i] == -1) p2.pb(i);
	}
	for (int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(mp(v,i));
		e[v].pb(mp(u,i));
	}
	if (p1.size()%2==1 && p2.size()==0){puts("-1");return 0;}
	if (p1.size()%2==1)
		col[p2[0]] = 1;
	memset(vis,false,sizeof(vis));
	memset(choose,false,sizeof(choose));
	vis[1] = true;
	dfs(1,0);
	
	for (int i=1;i<=M;i++)
	if (choose[i])
		ans.pb(i);
	printf("%d\n",ans.size());
	for (auto t:ans) printf("%d\n",t);
}
