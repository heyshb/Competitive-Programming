#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL a[500010];
LL s[500010];

int main()
{
	int Q;
	scanf("%d",&Q);
	double ans = 0;
	int N = 0;
	while(Q--)
	{
		int type;
		scanf("%d",&type);
		if (type == 1)
		{
			N++;
			scanf("%lld",&a[N]);
			s[N] = s[N - 1] + a[N];
			if (N > 1)
			{
				int L = 1, R = N;
				while(L < R - 1)
				{
					LL mid = (L + R) / 2;
					if (a[mid] * mid - s[mid - 1] <= a[N])
						L = mid;
					else
						R = mid;
				}
				ans = max(ans,a[N] - 1.0 * (s[L] + a[N]) / (L + 1));
			}
		}
		else
		{
			printf("%.10lf\n",ans);
		}
	}
} 
