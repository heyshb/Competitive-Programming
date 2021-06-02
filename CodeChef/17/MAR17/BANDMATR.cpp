#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N , ans = 0, v ,S = 0;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
			{
				scanf("%d",&v);
				S+=v;
			}
		int tmp = N;
		for (int i=N-1;i>=1;i--)
		{
			if (tmp>=S) break;
			ans++;
			tmp+=2*i;
		}
		printf("%d\n",ans);
	}
}
