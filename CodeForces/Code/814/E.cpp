#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
LL f[52][52][110][110];
LL s[52][52][110]; 
int d[51];
int N;

LL pp(LL a,LL x)
{
	LL res = 1;
	for (LL i=1;i<=x;i++)res=res*a%MOD;
	return res;
}

LL C(LL N,LL M)
{
	if (M == 1) return N;
	if (M == 2) return (N-1)*N/2;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&d[i]);
	LL ans = 0;
	memset(f,0,sizeof(f));
	f[1][0][0][d[1]] = 1;
	for (int i=2;i<=N;i++)
		for (int j=1;j<=i;j++)
			for (int k=0;k<=2*N;k++)
				for (int l=0;l<=2*N;l++)
				{
					for (int p=0;p<=d[i]-1;p++)//p forward d[i]-1-p afterward
					{
						int x = l+2*p-d[i]-1;
						if (x<=p) continue;
						f[i][j][k][l] = (f[i][j][k][l] + (f[i-1][j][k+1][x] * C(k+1,1)) % MOD * C(x,2) % MOD) % MOD;
					}
					
					for (int p=0;p<=d[i]-1;p++)
					{
						int x = 
						f[i][j][k][l] = (f[i][j][k][l] + (f[i-1][j-1][k+1][x] * C(k+1,1)) % MOD * C(x,2) % MOD) % MOD;
					}
					
					if (i == N) ans = (ans + f[i][j][k][l]) % MOD;
				}
	printf("%lld\n",ans);
}
