#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve(LL N,LL K,LL S)
{
	//3printf("Solve %lld %lld %lld\n",N,K,S);
	N--;
	K--;
	LL L = N/2, R = N - N/2;
	if (K==0)
	{
		printf("%I64d\n",S+L+1);
		return;
	}
	if (K&1)
	{
		solve(L,(K+1)/2,S);
	}
	else
	{
		solve(R,K/2,S+L+1);
	}
}

int main()
{
	LL N,K;
	scanf("%I64d%I64d",&N,&K);
	if (K==1) return 0*puts("1");
	if (K==2) return 0*printf("%I64d\n",N);
	solve(N-2,K-2,1);
}
