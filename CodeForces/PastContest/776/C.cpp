#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

unordered_map<LL,int> sum;

int N;
LL K;
LL up = 2e16;

int main()
{
	sum.clear();
	sum[0] = 1;
	scanf("%d%I64d",&N,&K);
	LL tmp,S = 0;
	LL ans = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%I64d",&tmp);
		S+=tmp;
		if (K==-1)
		{
			ans+=sum[S-1];
			ans+=sum[S+1];
		}
		else if (K==1)
		{
			ans+=sum[S-1];
		}
		else
		{
			for (LL po=1LL;abs(po)<=up;po*=K)
			{
				ans+=sum[S-po];
			}
		}
		sum[S]++;
	}
	printf("%I64d\n",ans);
}
