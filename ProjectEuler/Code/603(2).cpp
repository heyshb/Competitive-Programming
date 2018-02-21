#include <bits/stdc++.h>
/*
#define N 2
#define K 1LL
*/
#define MOD 1000000007
using namespace std;


#define N 1000000
#define K 1000000000000LL

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

LL mul(LL &x,LL y)
{
	x = (x * y) % MOD;
}

LL add(LL &x,LL y)
{
	x = ((x + y) % MOD + MOD) % MOD;
}

LL muli(LL x,LL y)
{
	return x * y % MOD;
}

LL addi(LL x,LL y)
{
	return ((x + y) % MOD + MOD) % MOD;
}

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
	LL R2 = rev(2LL); 
	LL k = K%MOD;
	LL R9 = rev(9LL);
	printf("%lld %lld %lld %lld\n",R2,R9,p10,R);
	for (LL p=0;p<length;p++)
	{
		LL nowdigit = digit[length - p];
		// 
		LL S = 0,tmp1,tmp2;
		
		tmp1 = length;
		tmp2 = k*k%MOD*(p10-1)%MOD*(p10-1)%MOD;
		//printf("%lld\n",tmp2);
		assert(tmp2 <= MOD);
		tmp2 = (-tmp2 + MOD) % MOD;
		tmp2 = (tmp2 - k * (p10-1) % MOD * (p10 + 2*quick_pow(10LL,p+1) - 1) % MOD);
		//printf("%lld\n",MOD-tmp2);
		tmp2 = (tmp2 + (quick_pow(10LL,K*length) - 1) * quick_pow(10LL,length+p+1) % MOD * 2LL % MOD);
		S = (S + tmp1 * tmp2 % MOD) % MOD;
		//printf("%lld\n",S);
		
		tmp1 = 2LL * (p10-1) % MOD * p % MOD;
		tmp2 = ((k * (p10-1) % MOD - quick_pow(10LL,p+1) * (quick_pow(10LL,K*length) -1) % MOD ) +MOD )% MOD;
		S = (S + tmp1 * tmp2 % MOD) % MOD;
		
		S = S * R2 % MOD * R % MOD * R % MOD;
		ans = (ans + (nowdigit * S) % MOD) % MOD;
	}
	mul(ans,R9);
	printf("%lld\n",ans);
}
