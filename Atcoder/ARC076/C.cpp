#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
LL fac[100010]; 

int main()
{
	fac[0] = 1;
	for (int i=1;i<=100000;i++)fac[i] = fac[i-1] * LL(i) % MOD;
	int N,M;
	scanf("%d%d",&N,&M);
	if (N<M) swap(N,M);
	if (N > M+1)
		return 0*puts("0");
	LL ans = 1;
	if (N==M)
	{	
		ans = 2LL*fac[N]*fac[M]%MOD;
	}
	else
	{
		ans = fac[N]*fac[M]%MOD;
	}
	printf("%lld\n",ans);
}
