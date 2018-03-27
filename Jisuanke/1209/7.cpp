#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1000010;
bool blk[MAXN];
int N;
int s[MAXN],premax[MAXN],sufmax[MAXN],v[MAXN],sufmin[MAXN],premin[MAXN];
int sz[MAXN];
vector<int>e[MAXN];
int ans = 0;
int cnt,now[MAXN],maxson[MAXN];
vector<int>st;
int maxs[5*MAXN],maxs2[5*MAXN];
int top,stk[MAXN],fa[MAXN];
bool vis[MAXN];

inline int readaaaa()
{
    int X=0,w=0; char ch=0;
    while(ch<'0' || ch>'9') {w|=ch=='-';ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

void dfs1(int X,int F)
{
	stk[top = 1] = X;
	fa[X] = F;
	while(top)
	{
		//printf("%d\n",top);
		int x = stk[top];
		if (!vis[x])
		{
			vis[x] = true;
			now[++cnt] = x;
			sz[x] = 1;
			maxson[x] = 0;
			for (int i=0;i<e[x].size();i++)
			if (!vis[e[x][i]] && !blk[e[x][i]])
			{
				fa[e[x][i]] = x;
				stk[++top] = e[x][i];
			}
		}
		else
		{
			for (int i=0;i<e[x].size();i++)
			if (e[x][i] != fa[x] && !blk[e[x][i]])
			{
				sz[x] += sz[e[x][i]];
				maxson[x] = max(maxson[x],sz[e[x][i]]);
			}
			top--;
		}
	}
}

void dfs2(int X,int F)
{
	fa[X] = F;
	stk[top = 1] = X;
	while(top)
	{
		int x = stk[top];
		if (!vis[x])
		{
			vis[x] = true;
			s[x] = s[fa[x]] + v[x];
			premax[x] = max(premax[fa[x]],s[x]);
			sufmax[x] = max(0,sufmax[fa[x]] + v[x]);
			sufmin[x] = min(sufmin[fa[x]] + v[x], v[x]);
			st.push_back(x);
			for (int i=0;i<e[x].size();i++)
			{
				//printf("?? %d %d\n",x,e[x][i]);
				if (!vis[e[x][i]] && !blk[e[x][i]])
				{
					stk[++top] = e[x][i];	
				}
			}
		}
		else top--;
	}
}

void solve(int x)
{
	//printf("solve %d\n",x);
	cnt = 0;
	dfs1(x,0);
	//printf("cnt = %d\n",cnt);
	//for (int i=1;i<=cnt;i++)printf("%d ",now[i]);puts("");
	int rt = -1, minsize = 10000000;
	for (int i=1;i<=cnt;i++)
	{
		int tmp = max(cnt - sz[now[i]], maxson[now[i]]);
		if (tmp < minsize)
		{
			minsize = tmp;
			rt = now[i];
		}
	}
	//printf("root = %d\n",rt);
	for (int i=1;i<=cnt;i++)vis[now[i]] = false;
	for (int i=-cnt-10;i<=cnt+10;i++)maxs[2*MAXN + i] = -10000000,maxs2[2*MAXN+i] = -10000000;
	s[rt] = 0;
	sufmin[rt] = 0;
	premax[rt] = 0;
	sufmax[rt] = 0;
	for (int i=0;i<e[rt].size();i++)
	{
		int t = e[rt][i];
		if (blk[t]) continue;
		st.clear();
		vis[rt] = true;
		dfs2(t,rt);
		for (auto tt:st)
		{
			//printf("premax[%d]=%d, sufmin[]=%d sufmax=%d\n",tt,premax[tt],sufmin[tt],sufmax[tt]);
			ans = max(ans,maxs[2*MAXN-v[rt]-s[tt]] + premax[tt]);
			if (sufmin[tt]>=0 && s[tt]+v[rt]>=0)
				ans = max(ans,s[tt] + v[rt] + maxs2[2*MAXN - v[rt] - s[tt]]);
			if (v[rt] == 1 && s[tt] == -1)
				ans = max(ans,1 + premax[tt]); 
		}
		for (auto tt:st)
		{
			if (sufmin[tt] >= 0 && s[tt] + v[rt] >= 0)
				maxs[2*MAXN + s[tt]] = max(maxs[2*MAXN + s[tt]], s[tt]);
			maxs2[2*MAXN + s[tt]] = max(maxs[2*MAXN + s[tt]], premax[tt]);
		}
	}
	for (int i=1;i<=cnt;i++)vis[now[i]] = false;
	blk[rt] = true;
	for (auto t:e[rt])
	if (!blk[t]) solve(t);
}

int main()
{
	//freopen("7.in","r",stdin);
	while(scanf("%d",&N) != EOF)
	{
		for (int i=1;i<=N;i++)e[i].clear();
		for (int i=1;i<=N;i++)
		{
			int f;
			//scanf("%d%d",&f,&v[i]);
			f = readaaaa();
			v[i] = readaaaa();
			if (f)
			{
				e[f].push_back(i);
				e[i].push_back(f);
			}
		}
		for (int i=1;i<=N;i++)blk[i] = false;
		for (int i=1;i<=N;i++)
		{
			s[i] = 0;
			maxs[i] = -10000000;
			premax[i] = 0;
			sufmin[i] = 10000000;
		}
		//puts("begin");
		ans = 0;
		solve(1);
		printf("%d\n",ans);
	}
}
