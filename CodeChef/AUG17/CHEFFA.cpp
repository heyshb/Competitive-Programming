#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
int N;
LL a[210];
LL f[210][210][210];

void update(LL &x,LL y)
{
	x = (x + y) % MOD;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&N);
		for (int i=1;i<=N;i++)scanf("%lld",&a[i]);
		memset(f,0,sizeof(f));
		LL ans = 0;
		f[2][a[2]][a[1]] = 1;
		for (int i=2;i<=150;i++)
		{
			//printf("%d\n",i);
			for (int j=0;j<=200;j++)
				for (int k=0;k<=200;k++)
				if (f[i][j][k])
					for (int l=0;l<=min(j,k);l++)
					{
						//if (i > 79)printf("%d %d %d %lld\n",i,a[i+1]+l,j-l,f[i][j][k]);
						update(f[i+1][a[i+1]+l][j-l], f[i][j][k]);
						//printf("%lld\n",f[i][j][k]);
					}
		}
		ans = f[151][0][0];
		printf("%lld\n",ans);
	}
}
