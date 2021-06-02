#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,a[2010];
int f[2010],g[2010];
int mf[2010][2],mg[2010][2];
int sum[2010][2];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]),a[i]--;
	for (int i=1;i<=N+1;i++)
	{
		sum[i][0] = sum[i-1][0];
		sum[i][1] = sum[i-1][1];
		if (i<=N) sum[i][a[i]]++;
	}
	int m0 = 0, m1 = 0;
	for (int i=1;i<=N;i++)
	{
		if (a[i] == 1)
		{
			f[i] = max(m0,m1) + 1;
			m1 = max(m1,f[i]);
		}
		else
		{
			f[i] = m0 + 1;
			m0 = max(m0,f[i]);
		}
		mf[i][0] = max(mf[i-1][0],m0);
		mf[i][1] = max(mf[i-1][1],m1);
	}
	m0 = 0, m1 = 0;
	for (int i=N;i>=1;i--)
	{
		if (a[i] == 1)
		{
			g[i] = m1 + 1;
			m1 = max(m1,g[i]);
		}
		else
		{
			g[i] = max(m0,m1) + 1;
			m0 = max(m0,g[i]);
		}
		mg[i][0] = max(mg[i+1][0],m0);
		mg[i][1] = max(mg[i+1][1],m1);
	}
	//for (int i=1;i<=N;i++)printf("%d %d %d %d\n",mf[i][0],mf[i][1],mg[i][0],mg[i][1]);
	int ans = 0;
	for (int i=1;i<=N;i++)
	{
		int maxd = -100000;
		for (int j=i;j<=N;j++)
		{
			maxd = max(maxd, sum[j][1] - sum[j][0]);
			int S0,S1;
			S0 = sum[j][0] - sum[i-1][0];
			S1 = sum[j][1] - sum[i-1][1];
			
			ans = max(ans,mf[i-1][0] + S0 + max(mg[j+1][0],mg[j+1][1]));
			ans = max(ans,max(mf[i-1][0],mf[i-1][1]) + S1 + mg[j+1][1]);
			ans = max(ans,mf[i-1][0] + maxd + mg[j+1][1] + sum[j+1][0] - sum[i-1][1]);
			//if (ans == 11) printf("%d %d\n",i,j);
		}
	}
	printf("%d\n",ans);
} 
