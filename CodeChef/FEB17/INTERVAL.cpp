#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL A[300010],S[300010];
LL f[2][300010];
int N,M;
int B[210]; 
int q[300010],head,tail;

LL sum(int L,int len)
{
	return S[L+len-1]-S[L-1];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		S[0] = 0;
		for (int i=1;i<=N;i++)
		{
			scanf("%lld",&A[i]);
			S[i] = S[i-1] + A[i];
		}
		for (int i=1;i<=M;i++)scanf("%d",&B[i]);
		B[M+1] = 0;
		for (int i=0;i<2;i++)
			for (int j=1;j<=N;j++)f[i][j]=0;
		int now = (M+1)&1, last = !now;
		for (int i=M;i>=1;i--)
		{
			now^=1;
			last^=1;
			if (i&1)
			{
				head = 1;
				tail = 0;
				for (int j=N-B[i+1];j>N-B[i]+1;j--)
				{
					while(tail > head && f[last][j]<=f[last][q[tail]]) tail--;
					q[++tail] = j;
				}
				for (int j=N-B[i]+1;j>=1;j--)
				{
					while(q[head] + B[i+1] >= j + B[i]) head++;
					f[now][j] = f[last][q[head]] + sum(j,B[i]);
					while(tail > head && f[last][j]<=f[last][q[tail]]) tail--;
					q[++tail] = j;
				}
			}
			else
			{
				head = 1;
				tail = 0;
				for (int j=N-B[i+1];j>N-B[i]+1;j--)
				{
					while(tail > head && f[last][j]>=f[last][q[tail]]) tail--;
					q[++tail] = j;
				}
				for (int j=N-B[i]+1;j>=1;j--)
				{
					while(q[head] + B[i+1] >= j + B[i]) head++;
					f[now][j] = f[last][q[head]] - sum(j,B[i]);
					while(tail > head && f[last][j]>=f[last][q[tail]]) tail--;
					q[++tail] = j;
				}
			}
			/*
			printf("%d:\n",i);
			for (int j=1;j<=N;j++)printf("%d ",f[now][j]);
			puts("");
			*/
		}
		LL ans = 0;
		for (int i=1;i<=N-B[1]+1;i++)ans=max(ans,f[now][i]);
		printf("%lld\n",ans);
	}
}
