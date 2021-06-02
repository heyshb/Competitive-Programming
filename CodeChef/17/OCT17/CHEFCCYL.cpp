#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
int N;
vector<int>e[MAXN],s[MAXN];
int L[MAXN],R[MAXN];
int sz[MAXN],d[MAXN];
int sd[MAXN],sc[MAXN];

int dis(int c,int u,int v)
{
	//printf("dis %d %d %d = ",c,u,v);
	if (--u == 0) u = sz[c];
	if (--v == 0) v = sz[c];
	if (u > v) swap(u,v);
	int d1 = s[c][v] - s[c][u];
	//printf("%d\n",min(d1,s[c][sz[c]] - d1));
	return min(d1,s[c][sz[c]] - d1);
}

int main()
{
	//freopen("CYCLE.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int Q;
		scanf("%d%d",&N,&Q);
		for (int i=1;i<=N;i++)e[i].clear(),s[i].clear();
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&sz[i]);
			e[i].resize(sz[i] + 1);
			s[i].resize(sz[i] + 1);
			s[i][0] = 0;
			for (int j=1;j<=sz[i];j++)scanf("%d",&e[i][j]),s[i][j] = s[i][j-1] + e[i][j];
		}
		sd[0] = 0;
		sc[0] = 0;
		for (int i=1;i<=N;i++)
			scanf("%d%d%d",&R[i],&L[i%N+1],&d[i]);
		for (int i=1;i<=N;i++)
		{
			sd[i] = sd[i-1] + d[i];
			sc[i] = sc[i-1] + dis(i,L[i],R[i]);
		}
		//for (int i=1;i<=N;i++)printf("%d:%d----%d %d %d\n",i,L[i],R[i],d[i],dis(i,L[i],R[i]));
		//for (int i=1;i<=N;i++)printf("%d: %d %d\n",i,sc[i],sd[i]);
		while(Q--)
		{
			int v1,c1,v2,c2;
			scanf("%d%d%d%d",&v1,&c1,&v2,&c2);
			if (c1 > c2)
			{
				swap(v1,v2);
				swap(c1,c2);
			}
			//printf("(%d,%d)---(%d,%d)\n",c1,v1,c2,v2);
			int ans1 = dis(c1,v1,R[c1]) + dis(c2,v2,L[c2]) + sc[c2-1] - sc[c1] + sd[c2 - 1] - sd[c1 - 1];
			int ans2 = dis(c1,v1,L[c1]) + dis(c2,v2,R[c2]) + sc[N] - sc[c2] + sc[c1 - 1] + sd[N] - sd[c2 - 1] + sd[c1 - 1];
			printf("%d\n",min(ans1,ans2));
		}
	}
}
