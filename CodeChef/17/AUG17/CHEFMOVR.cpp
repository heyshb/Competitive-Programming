#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,D;
LL A[100010];

int solve()
{
	scanf("%d%d",&N,&D);
	LL S = 0;
	for (int i=1;i<=N;i++)scanf("%lld",&A[i]),S += A[i];
	if (S % N != 0) return puts("-1");
	S /= N;
	LL ans = 0;
	for (int i=1;i<=N;i++)
	if (A[i] != S)
	{
		if (i + D > N) return puts("-1");
		LL delta = (S - A[i]);
		A[i] += delta;
		A[i+D] -= delta;
		ans += abs(delta);
	}
	printf("%lld\n",ans);
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
