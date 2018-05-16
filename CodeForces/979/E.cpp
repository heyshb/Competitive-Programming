#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;
int N,K; 
int A[100];
LL f[60][2][60][60][60];
LL C[60][60],D[60][60],po[60];

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	po[0] = 1;
	for (int i=1;i<=50;i++)po[i] = po[i-1] * 2LL % MOD;
	C[0][0] = 1;
	for (int i=1;i<=50;i++)
		for (int j=0;j<=i;j++)
		{
			if (j == 0) C[i][j] = 1;
			else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	for (int i=0;i<=50;i++)
		for (int j=0;j<=i;j++)
			D[i][j & 1] = (D[i][j & 1] + C[i][j]) % MOD;
	
	
	
	f[0][0][0][0][0] = 1;
	for(int i=1;i<=N;i++) 
	for(int a=0;a<=i;a++) 
	for(int b=0;a+b<=i;b++) 
	for(int c=0;a+b+c<=i;c++)
    {
        int d = i-a-b-c;
        if(A[i] != 1)
        {
            if(a)
            {
                f[i][0][a][b][c] = (
                    f[i][0][a][b][c] +
                    f[i-1][0][a-1][b][c] * po[a+b-1] % MOD * D[c][0] % MOD * D[d][1] % MOD
                ) % MOD;
                f[i][1][a][b][c] = (
                    f[i][1][a][b][c] +
                    f[i-1][1][a-1][b][c] * po[a+b-1] % MOD * D[c][0] % MOD * D[d][1] % MOD
                ) % MOD;
            }
            if(b)
            {
                f[i][0][a][b][c] = (
                    f[i][0][a][b][c] +
                    f[i-1][1][a][b-1][c] * po[a+b-1] % MOD * D[c][0] % MOD * D[d][0] % MOD
                ) % MOD;
                f[i][1][a][b][c] = (
                    f[i][1][a][b][c] +
                    f[i-1][0][a][b-1][c] * po[a+b-1] % MOD * D[c][0] % MOD * D[d][0] % MOD
                ) % MOD;
            }
        }
        if(A[i] != 0)
        {
            if(c)
            {
                f[i][0][a][b][c] = (
                    f[i][0][a][b][c] +
                    f[i-1][0][a][b][c-1] * po[c+d-1] % MOD * D[a][0] % MOD * D[b][1] % MOD
                ) % MOD;
                f[i][1][a][b][c] = (
                    f[i][1][a][b][c] +
                    f[i-1][1][a][b][c-1] * po[c+d-1] % MOD * D[a][0] % MOD * D[b][1] % MOD
                ) % MOD;
            }
            if(d)
            {
                f[i][0][a][b][c] = (
                    f[i][0][a][b][c] +
                    f[i-1][1][a][b][c] * po[c+d-1] % MOD * D[a][0] % MOD * D[b][0] % MOD
                ) % MOD;
                f[i][1][a][b][c] = (
                    f[i][1][a][b][c] +
                    f[i-1][0][a][b][c] * po[c+d-1] % MOD * D[a][0] % MOD * D[b][0] % MOD
                ) % MOD;
            }
        }
    } 
    LL ans = 0;
    for(int a=0;a<=N;a++) 
		for(int b=0;a+b<=N;b++) 
			for(int c=0;a+b+c<=N;c++) 
				ans = (ans + f[N][K][a][b][c]) % MOD;
    printf("%lld",ans);
}
