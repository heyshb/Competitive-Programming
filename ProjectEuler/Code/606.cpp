#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL B = 1000000,N = B*B, MOD = 1000000000; 
bool ok[B+10];
int cnt = 0;
LL prime[B+10];

LL cub(LL x)
{
	x%=MOD;
	return ((x*x)%MOD)*x%MOD;
}

LL sumNcub(LL x)//1^3+2^3..+x^3
{
	x %= MOD;
	LL tmp = x*(x+1)/2;
	tmp %= MOD;
	LL sss = 0;
	//for (LL i=1;i<=x;i++)sss=(sss+cub(i))%MOD;
	//assert(tmp*tmp%MOD == sss);
	return tmp * tmp % MOD;
}

vector<LL>V;
unordered_map<LL,LL>S;
LL calc(LL n)
{
	V.clear();
	S.clear();
	LL r = LL(sqrt(n));
	if ((r+1)*(r+1) <= n) r++;
	for (LL i=1;i<=r;i++) V.push_back(n/i);
	for (LL i=n/r-1;i>=1;i--) V.push_back(i);
	//puts("calc");
	//for (auto t:V) printf("%lld\n",t);
	//puts("");
	for (auto t:V) 
	{
		S[t] = sumNcub(t) - 1;
		//printf("%lld %lld\n",t,S[t]);
	}
 	for (LL p=2;p<=r;p++)
	{
		if (ok[p])
		{
			LL sp = S[p-1];
			LL p2 = p*p;
			for (auto v:V)
			{
				if (v<p2) break;
				S[v] = (S[v] - cub(p) * ((S[v/p] - sp + MOD) % MOD) % MOD + MOD) % MOD;
				//S[v]-=cub(p)*(S[v/p]-sp);
			}
		}
	}
	//printf("calc %lld = %lld\n",n,S[n]);
	return S[n];
}

int main()
{
	memset(ok,true,sizeof(ok));
	for (int i=2;i<=B;i++)
	{
		if (ok[i])
			prime[++cnt] = i;
		for (int j=1;j<=cnt && i*prime[j]<=B;j++)
		{
			ok[i * prime[j]] = false;
			if (i % prime[j] == 0) break;
		}
	}
	//printf("%d\n",cnt);
	//for (int i=1;i<=10;i++)printf("%d\n",prime[i]);
	//for (int i=1;i<=20;i++)printf("%lld\n",N/prime[i]);
	
	
	LL ans = 0;
	
	/*
	for (int i=2;i<=10000;i++)
		if (ok[i])
			ans = (ans + cub(i)) % MOD;
	printf("%lld\n",calc(10000));
	*/
		
	printf("Cnt = %d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		//printf("%lld %lld\n",prime[i],N/prime[i]);
		ans = ans + cub(prime[i]) * ((calc(N/prime[i]) - calc(prime[i]) + MOD) % MOD) % MOD;
		ans %= MOD;
		if (i<10 || i%100==0) printf("%d\n",i);
	}
	printf("%lld\n",ans);
}
