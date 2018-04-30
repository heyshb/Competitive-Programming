#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9+7;
LL f[2510][3][3][3],S[2510][3][3][3];
int N;
LL rev2 = (MOD + 1) / 2;

void upd(LL &x,LL y)
{
	y %= MOD;
	x = x + y;
	if (x >= MOD) x -= MOD;
}

void updall(LL &x,int np)
{
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			for (int k=0;k<3;k++)upd(x,S[np][i][j][k]);
}

LL gauss(LL x)
{
	return x*(x+1)%MOD*rev2%MOD;
}

int main()
{
	f[0][0][0][0] = 1;
	S[0][0][0][0] = 1;
	for (int N=1;N<=2500;N++)
	{
		updall(f[N][0][0][0],N-1);
		if (N>1) 
		{
			f[N][1][0][1] = 
			f[N][0][0][1] = 
			f[N][0][1][0] = 
			f[N][1][0][0] = S[N-1][0][0][0] - 1;
		}
		for (int j=N-1;j>=1;j--)
		{
			//upd(f[N][1][1][0],f[j-1][0][0][0]);
			upd(f[N][1][1][0],f[j][0][0][0]);
			upd(f[N][1][1][0],1LL*(N-j)*f[j][1][0][0]);
			upd(f[N][1][1][0],1LL*(N-j)*f[j][2][1][0]);
			upd(f[N][1][1][0],1LL*(N-j)*f[j][2][0][1]);
		}
		f[N][0][1][1] = f[N][1][1][0];
		for (int j=N-2;j>=1;j--)
		{
			upd(f[N][2][1][0],f[j][0][0][0] * (N - j - 1));
			LL x = 0;
			upd(x,f[j][1][0][0]);
			upd(x,f[j][2][0][1]);
			upd(x,f[j][2][1][0]);
			LL range = N - j - 1;
			x = x * gauss(range) % MOD;
			upd(f[N][2][1][0],x);
		}
		f[N][1][2][0] = f[N][0][2][1] = f[N][0][1][2] = f[N][2][1][0];
		
		if (N >= 2)
		{
			for (int i=N-2;i>=1;i--)
			{
				upd(f[N][2][0][1],f[i][0][0][0] * (N-i-1));
			}
			f[N][1][0][2] = f[N][2][0][1];
		}
		
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
				{
					S[N][i][j][k] = S[N-1][i][j][k];
					upd(S[N][i][j][k],f[N][i][j][k]);
					//if (f[N][i][j][k]) printf("f[%d][%d][%d][%d] = %lld\n",N,i,j,k,f[N][i][j][k]);
				}
	}
	freopen("13_submit.in","r",stdin);
	freopen("13_submit.out","w",stdout);
	int Case=100;
	scanf("%d",&Case);
	for (int _=1;_<=Case;_++)
	{
		int N;
		scanf("%d",&N);
		assert(N <= 2500); 
		//N = _;printf("%d: ",N);
		printf("Case #%d: %lld\n",_,f[N][0][0][0]);
	}
}
