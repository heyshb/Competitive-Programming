#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int K,Q;
double f[10010][1010];
double eps = 1e-7;

int main()
{
	scanf("%d%d",&K,&Q);
	f[1][1] = 1;
	for (int i=2;i<=10000;i++)
		for (int j=1;j<=min(i,K);j++)
		{
			f[i][j] = f[i-1][j]*double(j)/double(K)+f[i-1][j-1]*double(K-j+1)/double(K);
		}
	while(Q--)
	{
		int P;
		scanf("%d",&P);
		for (int i=1;i<=10000;i++)
		if (f[i][K]>(P-eps)/2000.0) 
		{
			printf("%d\n",i);
			break;
		}
	}
}
