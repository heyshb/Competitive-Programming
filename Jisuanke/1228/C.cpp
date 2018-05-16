#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL a[100010]; 
int pos[100010];
int book[100010];
vector<int>e[100010];
bool vis[100010];
int dfn[100010],low[100010];
int stk[100010],top;
int tnc = 0;
int color[100010],col = 0;
LL sum[100010];
bool ok[100010];

void dfs(int x)
{
	dfn[x] = ++tnc;
	low[x] = tnc;
	vis[x] = true;
	stk[++top] = x;
	for (auto t:e[x])
	{
		if (!dfn[t])
		{
			dfs(t);
			low[x] = min(low[x],low[t]);
		}
		else if (vis[t])
		{
			low[x]= min(low[x],dfn[t]);
			//printf("upd %d %d\n",x,t);
		}
	}
	if (dfn[x] == low[x])
	{
		vis[x] = false;
		color[x] = ++col;
		while(stk[top] != x)
		{
			color[stk[top]] = col;
			vis[stk[top--]] = false;
		}
		top--;
	}
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lld",&a[i]),pos[i] = i,book[i] = i;
	int M;
	scanf("%d",&M);
	memset(e,false,sizeof(e));
	while(M--)
	{
		int type;
		scanf("%d",&type);
		if (type == 0)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			pos[++N] = x;
			a[N] = y;
			book[x] = N;
		}
		else
		{
			int x,l,r;
			scanf("%d%d%d",&x,&l,&r);
			for (int i=l;i<=r;i++)
			{
				e[book[x]].push_back(book[i]);
				//printf("add %d %d\n",book[x],book[i]);
			}
		}
	}
	for (int i=1;i<=N;i++)
	if (!dfn[i]) dfs(i);
	LL ans = 1e18;
	for (int i=1;i<=N;i++)sum[color[i]] += a[i];
	memset(ok,true,sizeof(ok));
	//for (int i=1;i<=N;i++)printf("%d\n",color[i]);
	for (int i=1;i<=N;i++)
		for (auto t:e[i])
		if (color[i] != color[t])
		{
			ok[color[i]] = false;	
		}
	for (int i=1;i<=col;i++)
	if (ok[i]) ans = min(ans,sum[i]);
	printf("%lld\n",ans);
}
