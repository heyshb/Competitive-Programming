#include <bits/stdc++.h>
#define N 2
#define K 1LL
#define MOD 1000000007
using namespace std;

/*
#define N 1000000
#define K 1000000000000LL
*/
typedef long long LL;

bool ok[N*20];
int cnt,prime[N+10];
int digit[N*10];
LL length;

LL quick_pow(LL a,LL x)
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

LL rev(LL x){return quick_pow(x,MOD-2);}

int main()
{
	memset(ok,true,sizeof(ok));
	for (int i=2;;i++)
	{
		if (ok[i])
		{
			prime[++cnt] = i;
			if (cnt == N) break;
		}
		for (int j=1;j<=cnt && i*prime[j] <= N*20;j++)
		{
			ok[i * prime[j]] = false;
			if (i%prime[j] == 0) break;
		}
	}
	length = 0;
	for (int i=1;i<=cnt;i++)
	{
		int nowlen = 0;
		int tmp = prime[i];
		do
		{
			nowlen++;
			tmp/=10;
		}
		while(tmp);
		length += nowlen;
		tmp = prime[i];
		for (int j=0;j<nowlen;j++)
		{
			digit[length - j] = tmp%10;
			tmp/=10;
		}
	}
	printf("%lld\n",K*length);
	LL ans = 0;
	LL p10 = quick_pow(10LL,length);
	LL R = rev(p10 - 1);
	for (LL p=0;p<length;p++)
	{
		LL nowdigit = digit[length - p];
		// 
		LL S = 0,tmp;
		S = (length - p) * quick_pow(10LL,p + K*length);
		
		
		
		printf("%lld %lld\n",p,S);
		tmp = length * quick_pow(10LL, p + length) % MOD;
		tmp = (tmp * (quick_pow(p10,K-1) - 1)) % MOD; 
		tmp = (tmp * R) % MOD;
		S = (S + tmp) % MOD; 
		
		
		
		printf("%lld %lld\n",p,S);
		tmp = (K*length - p) % MOD;
		tmp = tmp * quick_pow(10LL,p) % MOD;
		S = (S - tmp + MOD) % MOD; 
		
		
		
		
		printf("%lld %lld\n",p,S);
		S = S * R % MOD;
		printf("%lld %lld\n",p,S);
		ans = (ans + (nowdigit * S) % MOD) % MOD;
	}
	printf("%lld\n",ans);
}
