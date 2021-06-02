#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K,X;
int sum[1300]; 
int modify[1300];

int main()
{
	scanf("%d%d%d",&N,&K,&X);
	for (int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		sum[tmp]++;
	}
	while(K--)
	{
		memset(modify,0,sizeof(modify));
		int last = 0;
		for (int i=0;i<=1200;i++)
		if (sum[i])
		{
			modify[i] = sum[i]/2;
			if (!last && (sum[i]&1)) modify[i]++;
			last = (last+sum[i])&1;
		}
		for (int i=0;i<=1200;i++)
		{
			sum[i]-=modify[i];
			sum[i^X]+=modify[i];
		}
	}
	int MAXV = -1000000,MINV = 1000000;
	for (int i=0;i<=1200;i++)
	if (sum[i])
	{
		MAXV = max(MAXV,i);
		MINV = min(MINV,i);
	}
	printf("%d %d\n",MAXV,MINV);
}
