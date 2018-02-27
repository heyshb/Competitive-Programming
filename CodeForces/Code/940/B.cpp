#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N,K,A,B;

int main()
{
	scanf("%lld%lld%lld%lld",&N,&K,&A,&B);
	if (N == 1) return 0 * puts("0");
	if (K == 1) return 0 * printf("%lld\n",A * (N - 1));
	LL ans = 0;
	while(N > 1)
	{
		if (N < K) 
		{
			ans += A * (N - 1);
			break;
		}
		LL nxt = N / K;
		ans += min(A * nxt * (K - 1), B) + A * (N - nxt * K);
		N = nxt;
	}
	printf("%lld\n",ans);
}
