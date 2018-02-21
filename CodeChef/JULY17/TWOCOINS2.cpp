#include <bits/stdc++.h>
#define rep for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<3;k++)for(int l=0;l<2;l++)
using namespace std;

int f[100010][2][2][3][2];//fa this son grson
int g[2][2][3][2];
int N;
vector<int>e[100010];

bool ok(int v1,int v2,int v3,int v4,int v5)
{
	if (v3)
	{
		return (v1 || v2 || v4 || v5);
	}
	else
	{
		return (v2 + v4 >= 2);
	}
}

void dfs(int x,int ff)
{
	rep f[x][i][j][k][l] = 1000000;
	f[x][0][0][0][0] = f[x][1][0][0][0] = 0;
	f[x][0][1][0][0] = f[x][1][1][0][0] = 1;
	for (auto t:e[x])
	if (t != ff)
	{
		dfs(t,x);
		// choose fa[x]    1 i j k
		rep g[i][j][k][l] = 1000000;
		
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				for (int k=0;k<3;k++)
					for (int l=0;l<2;l++)
						for (int ii=0;ii<2;ii++)
							for (int jj=0;jj<3;jj++)
								for (int kk=0;kk<2;kk++)
								{
									if (ok(i,j,ii,jj,kk))
									{
										int n1 = i;
										int n2 = j;
										int n3 = min(2,k+ii);
										int n4 = min(1,l+jj);
										g[n1][n2][n3][n4] = min(g[n1][n2][n3][n4],f[x][i][j][k][l] + f[t][j][ii][jj][kk]);
									}
								}
				
			
		rep f[x][i][j][k][l] = g[i][j][k][l];
	}
	//printf("%d:\n",x);
	//rep printf("[%d][%d][%d][%d][%d] = %d\n",x,i,j,k,l,f[x][i][j][k][l]);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		if (N == 1)
		{
			puts("-1");
			continue;
		}
		for (int i=1;i<=N;i++)e[i].clear();
		for (int i=1;i<N;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		int ans = 1000000;
		for (int i=0;i<2;i++)
			for (int j=0;j<3;j++)
				for (int k=0;k<2;k++)
				if (ok(0,0,i,j,k))
				ans = min(ans,f[1][0][i][j][k]);
		printf("%d\n",ans);
	}
}
