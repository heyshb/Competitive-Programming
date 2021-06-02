#include <bits/stdc++.h>

using namespace std;

bool vis[200010];
int T,N,K;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&K);
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=N;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			vis[tmp] = true;
		}
		for (int i=0;i<=200005;i++)
		if (!vis[i])
		{
			if (K==0)
			{
				printf("%d\n",i);
				break;
			}
			K--;
		}
	}
}
