#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool use[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		if (N%2==0)
		{
			for (int i=1;i<=N;i++)
			{
				if (i%2)
					printf("%d",i+1);
				else
					printf("%d",i-1);
				if (i == N) puts("");
				else printf(" ");
			}
		}
		else
		{
			for (int i=1;i<=N-3;i++)
			{
				if (i%2)
					printf("%d ",i+1);
				else
					printf("%d ",i-1);
			}
			printf("%d %d %d\n",N-1,N,N-2);
		}
	}
}
