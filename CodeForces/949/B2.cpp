#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL N,Q;

int main()
{
	scanf("%lld%lld",&N,&Q);
	while(Q--)
	{
		LL x;
		scanf("%lld",&x);
		if (x % 2 == 1)
		{
			printf("%lld\n",(x + 1) / 2);
			continue;
		}
		x = N - (x / 2);
		while(x % 2 == 0) x /= 2;
		x = (x + 1) / 2;
		printf("%lld\n", N + 1 - x);
	}
}
