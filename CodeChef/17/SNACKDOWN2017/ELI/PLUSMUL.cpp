#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

LL quick_pow(LL a,LL x)
{
	LL res = 1;
	while(x)
	{
		if (x&1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return res;
}

int N;
LL p2[100010];
LL f[100010],s[100010],a[100010],r[100010];

int main()
{
	p2[0] = 1;
	for (int i=1;i<=100000;i++)
		p2[i] = p2[i-1] * 2LL % MOD; 
	int T;
	scanf("%d",&T);
	while(T--)
	{
		s[0] = 1;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
		{
			scanf("%lld",&a[i]);
			s[i] = s[i-1] * a[i] % MOD;
		}
		r[N] = quick_pow(s[N],MOD-2);
		for (int i=N-1;i>=1;i--)
			r[i] = r[i+1] * a[i+1] % MOD;
		LL ans = 0;
		LL sf = 0,sr = 1;
		for (int i=1;i<=N;i++)
		{
			f[i] = sf;
			f[i] = (f[i] + sr*s[i]) % MOD;
			sf = (sf + f[i]) % MOD;
			sr = (sr + p2[i-1] * r[i]) % MOD;
		}
		printf("%lld\n",f[N]);
	}
}
