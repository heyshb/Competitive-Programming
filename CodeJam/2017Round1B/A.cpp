#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("Al.in","r",stdin);
	freopen("Al.out","w",stdout);
	int T,D,N;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		double ans = 0;
		scanf("%d%d",&D,&N);
		for (int i=1;i<=N;i++)
		{
			double K,S;
			scanf("%lf%lf",&K,&S);
			ans = max(ans,(D-K)/S);
		}
		printf("Case #%d: %.6lf\n",_,D/ans);
	}
}
