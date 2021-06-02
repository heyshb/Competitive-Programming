#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K;
LL H[100010];
LL f[52][100010];
const LL INF = 1e12;

LL solve()
{
	LL res = 0;
	memset(f,0,sizeof(f));
	for (int i=1;i<=N;i++)f[0][i] = -INF;
	for (int k=1;k<=K+1;k++)
	{
		for (int i=1;i<=N;i++)
		{
			//printf("%d %d\n",k,i);
			LL mi = H[i];
			int last = -1;
			for (int j=i-1;j>=0;j--)
			if (H[j] < mi)
			{
				if (last == -1) last = j;
				mi = H[j];
				//printf("%d--->%d %lld+%lld=%lld\n",j,i,f[k-1][j],H[i] * (i-last) + H[j] * (last - j),f[k-1][j] + H[i] * (i-last) + H[j] * (last - j));
				f[k][i] = max(f[k][i],f[k-1][j] + H[i] * (i-last) + H[j] * (last - j));
			}
			//printf("f[%d][%d]=%lld\n",k,i,f[k][i]);
			LL tmp = f[k][i];
			for (int j=i+1;j<=N&&H[j]>=H[i];j++)
				tmp += H[i];
			//if (tmp > 100000) printf("wow %d %d %lld %lld\n",k,i,f[k][i],tmp);
			res = max(res,tmp);
		}
	}
	return res;
}

int main()
{
	freopen("WEA.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&K);
		for (int i=1;i<=N;i++)scanf("%lld",&H[i]);
		LL ans = solve();
		reverse(H+1,H+N+1);
		ans = max(ans,solve());
		printf("%lld\n",ans);	
	}
}
