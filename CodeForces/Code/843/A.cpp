#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct ele
{
	int v,id;
}e[100010];
bool cmp(ele a,ele b){return a.v < b.v;}
int v[100010],N;
bool vis[100010];
int cnt;
vector<int>ans[100010];

void dfs(int x)
{
	vis[x] = true;
	ans[cnt].push_back(x);
	if (!vis[v[x]]) dfs(v[x]);
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&e[i].v),e[i].id = i;
	sort(e+1,e+N+1,cmp);
	for (int i=1;i<=N;i++)v[i] = e[i].id;
	memset(vis,false,sizeof(vis));
	cnt = 0;
	for (int i=1;i<=N;i++)
	if (!vis[i])
	{
		cnt++;
		dfs(i);
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d",ans[i].size());
		for (auto t:ans[i]) printf(" %d",t);
		puts("");
	}
}
