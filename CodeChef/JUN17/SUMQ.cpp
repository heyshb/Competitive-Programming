#include <bits/stdc++.h>

typedef long long LL;
const LL MOD = 1000000007;
LL v[4][100010],s[4][100010],s2[4][100010];
int cnt[4];

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for (int i=0;i<3;i++)scanf("%d",&cnt[i]);
		for (int i=0;i<3;i++)
		{
			for (int j=1;j<=cnt[i];j++)scanf("%lld",&v[i][j]);
			sort(v[i]+1,v[i]+cnt[i]+1);
			s[i][0] = 0;
			for (int j=1;j<=cnt[i];j++)
			{
				s[i][j] = (s[i][j-1] + v[i][j] ) % MOD;
				s2[i][j] = (s2[i][j-1] + v[i][j] * v[i][j]) % MOD;
			}
		}
		LL p0 = 0, p2 = 0;
		LL ans = 0;
		for (int i=1;i<=cnt[1];i++)
		{
			LL y = v[1][i];
			while(p0 < cnt[0] && v[0][p0+1] <= y) p0++;
			while(p2 < cnt[2] && v[2][p2+1] <= y) p2++;
			ans = ans + (y*y%MOD)*(p0*p2%MOD)%MOD;
			ans = ans + (p0*s[2][p2]%MOD + p2*s[0][p0]%MOD) * y % MOD;
			ans = ans + s[0][p0] * s[2][p2] % MOD;
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
}
