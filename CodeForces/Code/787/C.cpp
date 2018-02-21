#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int K[2];
int S[2][7010];
int v[2][7010];//1 win -1 lose 0 ??
bool vis[2][7010];

int pre(int X,int step)
{
	X-=step;
	if (X<=0) X+=N;
}

void print(int V)
{
	if (V==0) printf("Loop ");
	else if (V==1) printf("Win ");
	else printf("Lose ");
}

int dfs(int pos,int nowplayer)
{
	//printf("%d %d\n",pos,nowplayer);
	if (pos==1) return -1;
	if (vis[nowplayer][pos]) return v[nowplayer][pos];
	vis[nowplayer][pos] = true;
	int next, sg = 1;
	for (int i=1;i<=K[nowplayer];i++)
	{
		next = pos + S[nowplayer][i];
		if (next > N) next -= N;
		//printf("%d %d--> %d\n",pos,nowplayer,next);
		sg = min(sg, dfs(next, nowplayer^1));
	}
	v[nowplayer][pos] = -sg;
	return v[nowplayer][pos];
	//printf("RT");
}

int main()
{
	scanf("%d",&N);
	for (int i=0;i<2;i++)
	{
		scanf("%d",&K[i]);
		for (int j=1;j<=K[i];j++)
			scanf("%d",&S[i][j]);
	}
	memset(v,0,sizeof(v));
	for (int i=2;i<=N;i++)print(dfs(i,0));
	puts("");
	for (int i=2;i<=N;i++)print(dfs(i,1));
}
