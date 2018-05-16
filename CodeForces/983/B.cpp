#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int a[5010],ans[5010][5010];
int f[5010][5010];
int mi[5010][5010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	for (int i=1;i<=N;i++)ans[i][0] = a[i], mi[i][0] = a[i];
	for (int j=1;j<=N;j++)
		for (int i=1;i+j<=N;i++)
		{
			ans[i][j] = ans[i][j-1] ^ ans[i+1][j-1];
			mi[i][j] = max(mi[i][j-1],ans[i][j]);
		}
	for (int i=N;i>=1;i--)
		for (int j=0;i+j<=N;j++)
		if (j == 0)
			f[i][j] = ans[i][j];
		else
		{
			f[i][j] = max(f[i+1][j-1],mi[i][j]);
		}
	/*
	for (int i=1;i<=N;i++)
		for (int j=0;i+j<=N;j++)
		printf("f[%d][%d] = %d, ans[%d][%d]=%d\n",i,j,f[i][j],i,j,ans[i][j]);*/
	int Q,L,R;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&L,&R);
		printf("%d\n",f[L][R-L]);
	}
}
