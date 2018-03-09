#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K;

int main()
{
	scanf("%d%d",&N,&K);
	int ans = N / (K + 1) * 2;
	int MOD = N % (K + 1);
	if (MOD > 0)
	{
		if (MOD == 1) ans++;
		else ans += 2;
	}
	printf("%d\n",ans);
}
