#include <bits/stdc++.h>

using namespace std;

int len[2510],v[2510][2510];
bool vis[2510];
int N,K;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&K);	
		int ans = 0;
		
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&len[i]);
			for (int j=1;j<=K;j++)vis[j] = false;
			for (int j=1;j<=len[i];j++)
			{
				int tmp;
				scanf("%d",&v[i][j]);
				vis[v[i][j]] = true;
			}
			for (int j=1;j<i;j++)
			{
				if (len[i] + len[j] < K) continue;
				int cnt = 0;
				for (int k=1;k<=len[j];k++)
					if (!vis[v[j][k]])
						cnt++;
				if (cnt + len[i] == K) 
				{
					//printf("%d %d\n",i,j);
					ans++;
				}
				
			}
		}
		printf("%d\n",ans);
	}
}
