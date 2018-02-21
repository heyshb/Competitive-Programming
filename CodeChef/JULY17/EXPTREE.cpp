#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL MOD1 = 1000000007;
LL MOD2 = 1000000009;

LL quick_pow(LL a,LL x,LL MOD)
{
	LL res = 1;
	a %= MOD;
	while(x)
	{
		if (x&1) res = res*a % MOD;
		x>>=1;
		a = a*a % MOD;
	}
	return res;
}

LL rev(LL x,LL MOD)
{
	return quick_pow(x,MOD-2,MOD);
}

//N(N+1)/(4N-2)

LL gao(LL N,LL MOD)
{
	LL res = 1;
	res = res*(N%MOD)%MOD;
	res = res*((N+1)%MOD)%MOD;
	res = res*(rev(4*N-2,MOD))%MOD;
	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL N;
		scanf("%lld",&N);
		if (N == 1)
			puts("0 0");
		else
		{
			N--;
			printf("%lld %lld\n",gao(N,MOD1),gao(N,MOD2));
		}
	}
}
