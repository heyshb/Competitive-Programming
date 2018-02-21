#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int cnt0,cnt1;
LL f[51][2];

int main()
{
	int N,P;
	scanf("%d%d",&N,&P);
	LL ans = 1;
	for (int i=1;i<=N;i++)
	{
		int x;
		scanf("%d",&x);
		if (x&1)
			cnt1++;
		else
			cnt0++;
	}
	f[0][0] = 1;
	f[0][1] = 0;
	for (int i=1;i<=cnt1;i++)
	{
		f[i][0] = f[i-1][0] + f[i-1][1];
		f[i][1] = f[i-1][0] + f[i-1][1];
	}
	ans = f[cnt1][P];
	for (int i=1;i<=cnt0;i++)
		ans <<= 1LL;
	printf("%lld\n",ans);
}
