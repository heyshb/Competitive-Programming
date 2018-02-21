#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,color[200010];
int pos[100010][2];
vector<int> e[200010];
bool vis[200010];

void dfs(int x,int co)
{
	color[x] = co;
	vis[x] = true;
	for (int i=0;i<e[x].size();i++)
	if (!vis[e[x][i]])
		dfs(e[x][i],3-co);
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		int X,Y;
		scanf("%d%d",&X,&Y);
		pos[i][0] = X;
		pos[i][1] = Y;
		e[X].push_back(Y);
		e[Y].push_back(X);
	}
	for (int i=1;i<=N;i++)
	{
		int X,Y;
		X = 2*i;
		Y = X-1;
		e[X].push_back(Y);
		e[Y].push_back(X);
	}
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=2*N;i++)
	if (!vis[i])
		dfs(i,1);
	for (int i=1;i<=N;i++)printf("%d %d\n",color[pos[i][0]],color[pos[i][1]]);
}
