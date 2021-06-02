#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N,A[110],B[110],L,C[110]; 

int main()
{
	scanf("%d%d",&N,&L);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=N;i++)scanf("%d",&B[i]);
	for (int i=1;i<=N;i++)
	{
		for (int j=i;j<=N;j++)C[j-i+1] = B[j] + (A[1]-B[i]);
		for (int j=1;j<i;j++)C[N-i+1+j] = B[j] + (A[1]-B[i]) + L; 
		bool flag = true;
		//for (int j=1;j<=N;j++)printf("%d ",C[j]);puts("");
		for (int j=1;j<=N;j++)if (C[j]!=A[j])flag = false;
		if (flag)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}
