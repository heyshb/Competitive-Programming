#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 1000000007;

LL quick_pow(LL a,LL x)
{
	LL res = 1;
	while(x)
	{
		if (x & 1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return res;
}

int main()
{
	LL N,M,K;
	scanf("%lld%lld%lld",&N,&M,&K);
	if (K == -1 && (N % 2 != M % 2))
	{
		puts("0");
		return 0;
	}
	N--;
	M--;
	N %= MOD-1;
	M %= MOD-1;
	printf("%lld\n",quick_pow(2LL,N*M));
}
