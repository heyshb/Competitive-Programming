#include <bits/stdc++.h>

using namespace std;

const int N = 100000000;
bool isprime[N + 10];
int mu[N + 10];
int cnt,prime[20000000];

typedef long long LL;

LL gao(LL up)
{
	return up * (up - 1) / 2;
}

int main()
{
	memset(isprime,true,sizeof(isprime));
	mu[1] = 1; 
	for (int i=2;i<=N;i++)
	{
		if (isprime[i]) prime[++cnt] = i, mu[i] = -1;
		for (int j=1;j<=cnt && i*prime[j]<=N;j++)
		{
			isprime[i*prime[j]] = false;
			if (i % prime[j] == 0) 
			{
				mu[i * prime[j]] = 0;
				break;
			}
			else mu[i * prime[j]] = -mu[i];
		}
	}
	//for (int i=1;i<=20;i++)printf("%d %d\n",i,mu[i]);
	LL ans = 1LL * (N + 2) * (N - 1) / 2;
	for (int i=1;i<=N;i++)
		ans -= 1LL * mu[i] * gao(N / i);
	ans *= 6LL;
	printf("%lld\n",ans);
} 
