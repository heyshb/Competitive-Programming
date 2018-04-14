#include <bits/stdc++.h>

using namespace std;

int T,N,A[100010],B[100010],M;

int main()
{
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)scanf("%d",&A[i]);
		M = 0;
		for (int i=1;i<=N;i+=2)B[++M] = A[i];
		sort(B+1,B+M+1);
		for (int i=1;i<=M;i++)A[i*2-1] = B[i]; 
		M = 0;
		for (int i=2;i<=N;i+=2)B[++M] = A[i];
		sort(B+1,B+M+1);
		for (int i=1;i<=M;i++)A[i*2] = B[i];
		int ans = -1;
		for (int i=1;i<N;i++)
		if (A[i] > A[i+1])
		{
			ans = i;
			break;
		}
		printf("Case #%d: ",_);
		if (ans == -1)
			puts("OK");
		else
			printf("%d\n",ans-1);
	}
} 
