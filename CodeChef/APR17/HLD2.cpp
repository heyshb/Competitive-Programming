#include <bits/stdc++.h>

using namespace std;
#define MAXD 19
int N;
vector<int>e[100010];
int cost[100010],f[100010],f2[100010];
int p[100010][MAXD],hson[100010];
typedef long long LL;
const int INF = 100000000;

void solve(int fa,int X)
{
	if (e[X].size() == 1 && X!=1)return;
	int maxf = -1;
	for (int i=0;i<e[X].size();i++)
	if (e[X][i] != fa)
	{
		int Y = e[X][i];
		solve(X,Y);
		if (f[Y] > maxf)
		{
			hson[X] = Y;
			maxf = f[Y];
		}
	}
	p[X][0] = hson[X];
	for (int i=1;i<MAXD;i++)
		p[X][i] = p[p[X][i-1]][i-1];
		
	for (int i=0;i<e[X].size();i++)
	if (e[X][i] != fa && e[X][i] != hson[X])
	{
		int Y = e[X][i];
		f2[X] = max(f2[X], f[Y] + 1);
	}
	f[X] = max(f2[X], f[hson[X]]);
	f[X] = max(f[X], f2[hson[X]] + 1);
	for (int i=0;i<MAXD;i++)
	{
		int Y = p[X][i];
		Y = hson[Y];
		if (!Y) break;
		f[X] = max(f[X], f2[Y] + i + 2);
	}
}

int main()
{
    cost[1] = 1;
    for (int i=2;i<=100000;i*=2)
    {
        cost[i]=cost[i/2]+1;
        cost[100000] = cost[i] + 1;
    }
    for (int i=100000;i>=1;i--)
    if (!cost[i])
        cost[i] = cost[i+1];
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	memset(f,0,sizeof(f));
    	memset(f2,0,sizeof(f2)); 
		memset(p,0,sizeof(p));
		memset(hson,0,sizeof(hson)); 
        scanf("%d",&N);
        for (int i=1;i<=N;i++) e[i].clear();
        for (int i=1;i<N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        solve(0,1);
        //for (int i=1;i<=N;i++)printf("%d: hson:%d f:%d f2:%d\n",i,hson[i],f[i],f2[i]);
        printf("%d\n",f[1]);
    }
}
