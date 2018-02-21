#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

double eps = 1e-5;

LL N = 100000000;//sqr(r)

LL sumodd(LL x)
{
	LL res = 0;
	if (x%2 == 0) x--;
	return (((x+1)/2)%MOD * (((x+1)/2)%MOD)) %MOD;
	//return (((x+1) % MOD) * (((x+1)/2) /2)%MOD ) %MOD;
}

LL fuck(LL x)
{
	LL res = 1,tmp = 1;
	for (LL i=1;i<=x;i++)
		for (LL j=1;j<=x;j++)
		if (j%2==1 && i%j==0)
		{
			if (i&1) res+=8*j;
			else res+=24*j;
			if (j*j<=i) tmp = res;
		}
	//printf("%I64d\n",tmp);
	return res;
}

int main()
{
	for (N = 1; N <= 10; N++)
	{
		LL A = N * N;
		//printf("%I64d\n",fuck(A));
		LL ans = 1;
		for (LL i = 1; i <= N; i++)
		{
			if (i & 1)
			{
				//printf("%I64d: %I64d %I64d\n",i,((A/i + 1) / 2),((A/i) / 2));
				ans += 8 * i * ((A/i + 1) / 2);
				ans %= MOD;
				ans += 24 * i * ((A/i) / 2);
				ans %= MOD;
			}
		}
		//printf("%I64d\n",ans);
		for (LL i = 1; i <= N; i++)
		{
			if (i&1)
			{
				ans += 8 * (sumodd(A/i) - sumodd(N) + MOD) % MOD;
				ans %= MOD;
			}
			else
			{
				ans += 24 * (sumodd(A/i) - sumodd(N) + MOD) % MOD;
				ans %= MOD;
			}
		}
		printf("%I64d\n",ans);
	}
}
