#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M,Q;
int A[1010],B[1010],C[1010],D[1010];

int main()
{
	scanf("%d",&N);
	A[0] = 1;
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=N;j++)
			C[j] = A[j-1];
		C[0] = 0;
		bool ok = true;
		for (int j=0;j<=N;j++)
		ok &= (C[j]+B[j]>=-1 && C[j]+B[j]<=1);
		for (int j=0;j<=N;j++)
		if (ok)
			C[j] += B[j];
		else
			C[j] -= B[j];
		for (int j=0;j<=N;j++)
		{
			B[j] = A[j];
			A[j] = C[j];
		}
	}
	printf("%d\n",N);
	for (int i=0;i<=N;i++)printf("%d%c",A[i]," \n"[i==N]);
	printf("%d\n",N-1);
	for (int i=0;i<N;i++)printf("%d%c",B[i]," \n"[i==N-1]);
}
