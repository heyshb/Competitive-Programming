#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL N = 10;
LL H;
bool ok[1000010];
vector<LL>prime;
LL ans = 0;

void dfs(LL mul,int pre)
{
	if (mul > N) return;
	for (LL tmp = mul; tmp <= N; tmp *= 2LL)
	{
		printf("%lld\n",tmp);
		ans++;
	}
	for (int i=pre;i<prime.size();i++)
		dfs(mul * prime[i], i);
}

int main()
{
	H = LL(sqrt(N) + 1);
	memset(ok,true,sizeof(ok));
	for (LL i=2;i<=H;i++)
	{
		if (ok[i]) prime.push_back(i);
		for (auto t:prime)
		{
			if (t * i > H) break;
			ok[t * i] = false;
			if (i % t == 0) break;
		}
	}
	//for (auto t:prime)printf("%lld\n",t);
	for (int i=1;i<prime.size();i++)
	{
		prime[i] = prime[i] * prime[i];
		printf("%lld\n",prime[i]);
	}
	dfs(1,1);
	printf("%lld\n",ans);
}
