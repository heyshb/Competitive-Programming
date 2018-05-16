#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,a[20010];
LL p,s;

int main()
{
	scanf("%d",&N);
	LL R = 0;
	for (int i=1;i<=N;i++)scanf("%d",&a[i]),R = max(R,1LL*a[i]);
	LL L = 0;
	scanf("%lld%lld",&p,&s);
	LL s0 = s;
	while(L < R - 1)
	{
		s = s0;
		LL mid = (L + R) / 2;
		for (int i=1;i<=N;i++)
		if (a[i] > mid)
		{
			s -= (a[i] - mid) * p;
		}
		if (s >= 0)
			R = mid;
		else
			L = mid;
	}
	printf("%lld\n",R);
}
