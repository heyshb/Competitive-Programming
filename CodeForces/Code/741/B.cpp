#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M,W;
int w[1010],b[1010];
int f[1010][1010];
int gcnt;
bool vis[1010];
vector<int>e[1010];
vector<int>group[1010];

void dfs(int x)
{
	vis[x] = true;
	group[gcnt].push_back(x);
	for (int i=0;i<e[x].size();i++)
	{
		int y = e[x][i];
		if (!vis[y]) dfs(y);
	}
}

int main()
{
	scanf("%d%d%d",&N,&M,&W);
	for (int i=1;i<=N;i++)scanf("%d",&w[i]);
	for (int i=1;i<=N;i++)scanf("%d",&b[i]);
	for (int i=1;i<=M;i++)
	{
		int X,Y;
		scanf("%d%d",&X,&Y);
		e[X].push_back(Y);
		e[Y].push_back(X);
	}
	memset(vis,false,sizeof(vis));
	gcnt = 0;
	for (int i=1;i<=N;i++)
	if (!vis[i])
	{
		gcnt++;
		dfs(i);
	}
	memset(f,0,sizeof(f));
	for (int i=1;i<=gcnt;i++)
	{
		for (int k=0;k<=W;k++)f[i][k] = f[i-1][k];
		int SB=0,SW=0;
		for (int j=0;j<group[i].size();j++)
		{
			
			int bnow = b[group[i][j]],wnow = w[group[i][j]];
			//printf("wupin %d: %d %d\n",group[i][j],wnow,bnow);
			SB+=bnow;
			SW+=wnow;
			for (int k=wnow;k<=W;k++)
			f[i][k] = max(f[i][k],f[i-1][k-wnow]+bnow);
		}
		//printf("Group %d:%d %d\n",i,SW,SB);
		for (int k=SW;k<=W;k++)
		{
			f[i][k] = max(f[i][k],f[i-1][k-SW]+SB);
			//printf("UPDATE %d %d:%d\n",i,k,f[i][k]);
		}
	}
	int ans = 0;
	for (int i=0;i<=W;i++)ans=max(ans,f[gcnt][i]);
	printf("%d\n",ans);
}
