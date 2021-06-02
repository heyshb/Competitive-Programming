#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int A[3][1010],f[3][1010];
int N;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=2;i++)
		for (int j=1;j<=N;j++)scanf("%d",&A[i][j]);
	for (int i=1;i<=2;i++)
		for (int j=1;j<=N;j++)
			f[i][j] = max(f[i-1][j], f[i][j-1]) + A[i][j];
		
	printf("%d\n",f[2][N]);
}
