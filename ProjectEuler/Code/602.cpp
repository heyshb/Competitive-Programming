#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define MOD 1000000007
#define MAXN 10000010
LL fac[MAXN + 10];
LL rev[MAXN + 10];

LL quick_pow(LL a,LL x)
{
	LL res = 1;
	while(x)
	{
		if (x&1) res = res*a % MOD;
		a = a*a % MOD;
		x >>= 1;
	}
	return res;
}

LL C(LL N,LL M)
{
	return (fac[N] * rev[M]) %MOD * rev[N-M] % MOD;
}

LL A(LL N,LL K)
{
	LL res = 0;
	for (LL j=0;j<=K+1;j++)
	{
		LL tmp = C(N+1,j) * quick_pow(K-j+1,N) % MOD;
		if (j & 1)
			res = (res - tmp + MOD ) % MOD;
		else
			res = (res + tmp ) %MOD;
	}
	return res;
}

LL c(LL N,LL K)
{
	return A(N,K-1);
}

int main()
{
	fac[0] = 1;
	for (int i=1;i<=MAXN;i++)fac[i] = fac[i-1] * LL(i) % MOD;
	rev[MAXN] = quick_pow(fac[MAXN], MOD-2);
	for (int i=MAXN-1;i>=0;i--)rev[i] = rev[i+1] * (i+1) % MOD;
	//printf("%lld\n",c(100,40));
	printf("%lld\n",c(10000000,4000000));
}
