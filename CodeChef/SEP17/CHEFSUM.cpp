#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int mi = 1000000,N,ans,tmp;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&tmp);
			if (tmp < mi)
			{
				mi = tmp;
				ans = i;
			}
		}
		printf("%d\n",ans);
	}
}
