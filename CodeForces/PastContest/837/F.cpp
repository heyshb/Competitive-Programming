#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
LL K;
LL a[70][400010];

int main()
{
	scanf("%d%lld",&N,&K);
	bool caicai = true;
	for (int i=1;i<=N;i++)
	{
		scanf("%lld",&a[0][i]);
		if (i <= N-2 && a[0][i]) caicai = false;
		if (a[0][i] >= K)
		{
			puts("0");
			return 0;
		}
	}
	if (caicai)
	{
		LL aa = a[0][N-1], bb = a[0][N], ans;
		if ((K - aa) % bb == 0)
		{
			ans = (K - aa) / bb;
		}
		else
		{
			ans = (K - aa) / bb + 1;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for (int i=1;;i++)
	{
		a[i][1] = 0;
		for (int j=2;j<=N+i;j++)
		{
			a[i][j] = a[i][j-1] + a[i-1][j-1];
			if (a[i][j] >= K)
			{
				printf("%d\n",i);
				return 0;
			}
		}
	}
}
