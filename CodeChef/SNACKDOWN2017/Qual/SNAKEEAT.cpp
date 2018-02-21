#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,Q;
LL L[100010],S[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&Q);
		for (int i=1;i<=N;i++)scanf("%lld",&L[i]);
		sort(L+1,L+N+1);
		S[0] = 0;
		for (int i=1;i<=N;i++)S[i] = S[i-1] + L[i];
		L[N+1] = 1e9+1;
		for (int i=1;i<=Q;i++)
		{
			LL K;
			scanf("%lld",&K);
			int l,r;
			l = 0, r = N+1;
			while(l != r-1)
			{
				int mid = (l+r) >> 1;
				if (L[mid] < K)
					l = mid;
				else
					r = mid;
			}
			if (l == 0)
			{
				printf("%d\n",N);
				continue;
			}
			int bd = l + 1;
			r = bd;
			l = 1;
			//printf("%d %d\n",l,r);
			while(l != r-1)
			{
				int mid = (l+r) >> 1;
				if (K * LL(bd - mid) - (S[bd-1] - S[mid-1]) <= mid - 1)
					r = mid;
				else
					l = mid;
			}
			printf("%d\n",N - r + 1);
		}
	}
}
