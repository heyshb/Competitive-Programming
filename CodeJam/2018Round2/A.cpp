#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int C,N;
int A[210],B[210];
char ans[210][210];
int L[210],R[210];

bool check()
{
	for (int i=1;i<=C;i++)
	if (A[i] != 1) return false;
	return true;
}

int main()
{
	freopen("A.in","r",stdin);
	int T = 1, _ = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++_);
		scanf("%d",&C);
		int S = 0;
		for (int i=1;i<=C;i++)
		{
			scanf("%d",&A[i]);
			if (A[i])
			{
				L[i] = S + 1;
				R[i] = S + A[i];
				S = R[i];
				//printf("%d %d\n",L[i],R[i]);
			}
		}
		if (A[1] == 0 || A[C] == 0)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		N = 1;
		for (int i=1;i<=200;i++)
			for (int j=1;j<=C;j++)ans[i][j] = '.';
		for (int i=1;i<=C;i++)
		if (A[i])
		{
			N = max(N,max(abs(R[i]-i),abs(i-L[i])) + 1);
			for (int j=L[i];j<=R[i];j++)
			{
				for (int k=j;k<i;k++)
				{
					ans[1 + (i - k)][k] = '\\';
				}
				for (int k=i+1;k<=j;k++)
					ans[1 + (k - i)][k] = '/';
 			}
		}
		printf("%d\n",N);
		for (int i=N;i>=1;i--)
		{
			for (int j=1;j<=C;j++)
			printf("%c",ans[i][j]);
			puts("");
		}
	}	
}
