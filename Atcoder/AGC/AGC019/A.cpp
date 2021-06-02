#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL v[10];

int main()
{
	for (int i=1;i<=4;i++)scanf("%lld",&v[i]);
	LL N;
	scanf("%lld",&N);
	LL v1 = min(4*v[1],min(2*v[2],v[3]));
	LL ans = min(v1 * N, (N/2) * v[4] + (N%2) * v1);
	printf("%lld\n",ans);
}
