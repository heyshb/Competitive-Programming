#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,D,A[110];

int main()
{
	scanf("%d%d",&N,&D);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	int ans = 10000000;
	for (int i=1;i<=N;i++)
	{
		for (int j=i;j<=N;j++)
		if (j==N || A[j+1]-A[i]>D)
		{
			ans = min(ans,i-1+(N-j));
			break;
		}
	}
	printf("%d\n",ans);
}
