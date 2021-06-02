#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	int A[100010];
	while(T--)
	{
		int N;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)scanf("%d",&A[i]);
		sort(A+1,A+N+1);
		A[0] = -1;
		A[N+1] = -1;
		for (int i=1;i<=N;i++)
		if ((A[i]!=A[i-1]+1 && A[i]!=A[i+1]-1) || (A[i]==A[i-1]))
		{
			printf("%d\n",A[i]);
			break;
		}
	}
}
