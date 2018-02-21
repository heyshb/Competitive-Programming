#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int N;
	LL ans1 = 1,ans2 = 1;
	scanf("%d",&N);
	while(N--)
	{
		int tmp;
		scanf("%d",&tmp);
		ans1 *= 3LL;
		if (tmp%2 == 0)
			ans2 *= 2LL;
	}
	printf("%lld\n",ans1 - ans2);
}
