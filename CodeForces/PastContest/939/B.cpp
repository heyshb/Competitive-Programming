#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N,K;
LL ans1,ans2,mx = -1;

int main()
{
	scanf("%lld%lld",&N,&K);
	for (LL i=1;i<=K;i++)
	{
		LL x;
		scanf("%lld",&x);
		if (mx < (N / x) * x)
		{
			mx = (N / x) * x;
			ans1 = i;
			ans2 = N / x;
		}
	}
	printf("%lld %lld\n",ans1,ans2);
} 
