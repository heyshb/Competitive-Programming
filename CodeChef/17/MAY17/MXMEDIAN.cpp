#include <bits/stdc++.h>

using namespace std;

int N;
int A[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for (int i=1;i<=2*N;i++)scanf("%d",&A[i]);
		sort(A+1,A+N*2+1);
		int mid = (N+1)/2;
		printf("%d\n",A[N+mid]);
		for (int i=1;i<=N;i++)
			printf("%d %d%c",A[i],A[i+N]," \n"[i==N]);
	}
}
