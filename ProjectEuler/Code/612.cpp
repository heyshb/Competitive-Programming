#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f[20][1024];
const int maxlen = 18;
const LL MOD = 1000267129;
LL po(int x)
{
	LL res = 1;
	for (int i=1;i<=x;i++)res = res * 10LL % MOD;
	return res;
}

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

LL rev(LL x){return quick_pow(x,MOD-2);}

int main()
{
	f[0][0] = 1;
	for (int i=1;i<=maxlen;i++)
		for (int j=0;j<1024;j++)
			for (int k=0;k<10;k++)
			if ((j | (1 << k) ) > 1)
			{
				f[i][j | (1 << k)] += f[i-1][j];
				if (f[i][j | (1 << k)] >= MOD) 
					f[i][j | (1 << k)] -= MOD;
			}
	for (int i=2;i<=maxlen;i++)
		for (int j=0;j<1024;j++)
		{
			f[i][j] += f[i-1][j];
			if (f[i][j] >= MOD)
				f[i][j] -= MOD;
		}
	
	LL ans = 0;
	for (int i=1;i<1024;i++)
		for (int j=1;j<1024;j++)
			if (i & j)
			{
				ans += f[maxlen][i] * f[maxlen][j] % MOD;
				if (ans >= MOD) ans -= MOD;
			}
	printf("%lld\n",ans);
	
	LL sum = 0;
	for (int i=1;i<1024;i++)sum += f[maxlen][i];
	printf("%lld\n",sum);
	
	
	for (int i=1;i<1024;i++)
	if (f[maxlen][i])
		printf("f[%d][%d] = %lld\n",maxlen,i,f[maxlen][i]);
	
		
	ans -= (po(maxlen) - 1);
	if (ans < 0)
		ans += MOD;
	printf("%lld\n",ans);
	printf("%lld\n",rev(2));
	//ans *= rev(2);
	ans *= 500133565ll;
	ans %= MOD;
	printf("%lld\n",ans);
	//print(ans);
	//printf("%lld\n",ans);
}
