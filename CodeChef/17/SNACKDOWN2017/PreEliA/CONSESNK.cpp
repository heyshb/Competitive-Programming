#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
LL L,A,B;
LL s[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld%lld%lld",&N,&L,&A,&B);
		for (int i=1;i<=N;i++)scanf("%lld",&s[i]);
		sort(s+1,s+N+1);
		B-=LL(N)*L;
		//printf("%lld---%lld\n",A,B);
		LL minx,maxx;
		if (N&1)
		{
			int mid = (N+1)/2;
			minx = maxx = s[mid] - (mid-1) * L;
		}
		else
		{
			int mid = N/2;
			minx = s[mid] - (mid-1) * L;
			maxx = s[mid+1] - mid * L;
			if (minx > maxx) swap(minx,maxx);
		}
		
		LL bestx;
		if (minx > B)
		{
			bestx = B;
		}
		else if (maxx < A)
		{
			bestx = A;
		}
		else
		{
			bestx = minx;	
		}
		LL ans = 0;
		for (int i=1;i<=N;i++)
			ans += abs(s[i] - (bestx+(i-1)*L));
		printf("%lld\n",ans);
	}
}
