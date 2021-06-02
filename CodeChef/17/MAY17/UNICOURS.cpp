#include <bits/stdc++.h>

using namespace std;

int N;
int A[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		int mv = 0;
		for (int i=1;i<=N;i++)scanf("%d",&A[i]),mv = max(mv,A[i]);
		printf("%d\n",N-mv);
	}
}
