#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL h[100010];
LL L[100010],R[100010];

int main()
{
	int T,N;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		LL sum = 0;
		for (int i=1;i<=N;i++)
		{
			scanf("%lld",&h[i]);
			sum += h[i];
		}
		L[0] = R[N+1] = 0;
		for (int i=1;i<=N;i++)
			L[i] = min(h[i],L[i-1] + 1);
		for (int i=N;i>=1;i--)
			R[i] = min(h[i],R[i+1] + 1);
		LL maxh = 0;
		for (int i=1;i<=N;i++)
			maxh = max(maxh,min(L[i],R[i]));
		LL minsum = maxh * maxh;
		printf("%lld\n",sum - minsum);
	}
}
