#include <bits/stdc++.h>

using namespace std;

int N,M,A[200010],B[100010];

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	while(M--)
	{
		int X,Y;
		scanf("%d%d",&X,&Y);
		A[X] = Y;
		for (int i=1;i<=N;i++)B[i] = A[i];
		sort(B+1,B+N+1);
		int ans = N;
		for (int i=1;i<=N;i++)printf("%d ",B[i]);puts("");
		for (int i=1;i<=N;i++)
		if (B[i] == i)
			for (int j=i;j>=1 && B[j]==B[i];j--)
			ans--;
		printf("%d\n",ans);
	}
}
