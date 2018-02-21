#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve(LL N,LL K,int C)
{
	//printf("Solve %lld %lld\n",N,K);
	N--;
	if (K==1)
	{
		printf("Case #%d: %lld %lld\n",C,N-N/2,N/2);
		return;
	}
	K--;
	LL L = N - N/2, R = N/2;
	if (K&1)
	{
		solve(L,(K+1)/2,C);
	}
	else
	{
		solve(R,K/2,C);
	}
}

int main()
{
	//freopen("Cl.in","r",stdin);
	//freopen("Cl.out","w",stdout);
	int Casi;
	scanf("%d",&Casi);
	for (int _=1;_<=Casi;_++)
	{
		LL N,K;
		scanf("%lld%lld",&N,&K);
		solve(N,K,_);
	}
}
