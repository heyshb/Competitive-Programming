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

LL rev(LL x)
{
	return quick_pow(x,MOD-2);
}

LL k,pa,pb;
LL p[1010];
LL f[1010];

LL solve(LL a0,LL t,LL p)
{
	LL p1 = (1-p+MOD)%MOD;
	p1 = rev(p1);
	LL s = a0 * t % MOD + a0 * p % MOD * p1 % MOD;
	s = s * p1 % MOD;
	printf("solve %lld %lld %lld = %lld\n",a0,t,p,s);
	return s;
}

int main()
{
	printf("%lld\n",4LL*rev(25)%MOD);
	scanf("%lld%lld%lld",&k,&pa,&pb);
	LL s = pa + pb;
	pa = pa * rev(s) % MOD;
	pb = pb * rev(s) % MOD;
	LL revb = rev((1-pb+MOD)%MOD); 
	p[0] = pb;
	for (int i=1;i<=k+5;i++)p[i] = p[i-1] * pa % MOD;
	memset(f,0,sizeof(f));
	f[0] = 1;
	LL S = 0;
	for (int i=1;i<k;i++)
	{
		f[i] = p[i] * rev(1 - pb + MOD) % MOD;
		S = (S + f[i]) % MOD;
	}
	LL ans = (1 - S + MOD) % MOD * solve(p[k]* rev(1 - pb + MOD) % MOD,k,pa);
	for (int i=1;i<k;i++)
	{
		printf("f[%d]=%lld\n",i,f[i]);
		LL S = 0;
		int j;
		printf("revb = %lld\n",revb);
		for (j=0;2*i+j<k;j++)
		{
			printf("j = %d\n",j);
			S = (S + p[j]) % MOD;
			f[2 * i + j] = (f[2 * i + j] + f[i] * p[j] % MOD % MOD) % MOD;	
			printf("%d += %lld\n",2*i+j,f[i] * p[j] % MOD  % MOD);
		}
		printf("S = %lld\n",S);
		LL a0 = p[j];
		ans = (ans + f[i] * (1-S+MOD) % MOD *solve(p[j] % MOD,k,pa)) % MOD;
	}
	printf("%lld\n",ans);
	/*
	for (int i=k-1;i>=0;i--)
	{
		LL S = i==0?pb:0;
		int j;
		for (j=(i==0?1:0);2*i+j<k;j++)
		{
			printf("j = %d\n",j);
			f[i] = (f[i] + (j + 1 + f[2*i+j]) % MOD * p[j] % MOD) % MOD;
			S = (S + p[j]) % MOD;
		}
		S = (1 - S + MOD) % MOD;
		f[i] = (f[i] + S * solve(p[j],j+1,pa) % MOD) % MOD;
	}
	LL ans = 0;
	printf("%lld\n",f[0] * (1 - pb + MOD) % MOD);*/
}
