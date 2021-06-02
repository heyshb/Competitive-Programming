#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M,P;
int A[2010],B[2010];
int f[2010][2010],mi[2010][2010]; 

int main()
{
	scanf("%d%d%d",&N,&M,&P);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=M;i++)scanf("%d",&B[i]);
	sort(A+1,A+N+1);
	sort(B+1,B+M+1);
	for (int i=0;i<=N;i++)
		for (int j=0;j<=M;j++)f[i][j] = 2e9+10;
	for (int i=0;i<=M;i++)
		f[0][i] = 0;
	for (int i=1;i<=N;i++)
		for (int j=i;j<=M;j++)
		{
			f[i][j] = f[i][j-1];
			f[i][j] = min(f[i][j],max(f[i-1][j-1],abs(A[i]-B[j])+abs(P-B[j])));
			//printf("f[%d][%d]=%d\n",i,j,f[i][j]);
			//printf("%d %d\n",A[i],B[j]);
		}
	printf("%d\n",f[N][M]);
}
