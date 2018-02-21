#include <bits/stdc++.h>

using namespace std;

//a(n) = n^((n-1)^2)

typedef long long LL;
const int MOD = 1000000007;
int main()
{
	int N;
	scanf("%d",&N);
	LL ans = 1;
	int m = (N - 1) * (N - 1);
	for (int i=1;i<=m;i++)
		ans = ans * N % MOD;
	printf("%lld\n",ans);
}
