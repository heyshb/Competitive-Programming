#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
struct func
{
	int A,B,C,D;
	double f(double x)
	{
		return A*x*x*x + B*x*x + C*x + D;
	}
	LL f(LL x)
	{
		return 1LL*A*x*x*x + 1LL*B*x*x + 1LL*C*x + 1LL*D;
	}
}e[100010];
int N;

int main()
{
	freopen("POLY.in","r",stdin);
	freopen("brute.out","w",stdout);
	int Cases;
	scanf("%d",&Cases);
	while(Cases--)
	{	
		scanf("%d",&N);
		for (int i=1;i<=N;i++)scanf("%d%d%d%d",&e[i].D,&e[i].C,&e[i].B,&e[i].A);
		int Q;
		scanf("%d",&Q);
		while(Q--)
		{
			LL x;
			scanf("%lld",&x);
			LL ans = 7e18;
			for (int i=1;i<=N;i++)
				ans = min(ans,e[i].f(x));
			printf("%lld\n",ans);
		}
	}
}
