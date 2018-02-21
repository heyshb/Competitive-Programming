#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	scanf("%d",&T);
	LL N,B;
	while(T--)
	{
		scanf("%lld%lld",&N,&B);// x+By = N   xy = y*(N-By) = -By2+Ny
		LL mid = LL(double(N)/(2LL*B));
		LL ans = 0;
		for (LL tmp = mid-5;tmp<=mid+5;tmp++)
		{
			if (tmp>=0 && tmp*B<=N)
				ans = max(ans,N*tmp-B*tmp*tmp);
		}
		printf("%lld\n",ans);
	}
}
