#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL A[3010],S[3010];
LL f[3010][3010];
int N,M;
int B[210]; 
const LL INF = 1e17;

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
		for (int i=M;i>=1;i--)
		{
			if (i&1)
			{
				for (int j=1;j+B[i]-1<=N;j++)
				{
					f[i][j] = sum(j,B[i]);
					LL tmp = INF;
					for (int k=j+1;k+B[i+1]<j+B[i];k++)
					{
						printf("%d %d\n",i,j,k);
						tmp=min(tmp,f[i+1][k]);
					}
					f[i][j]+=tmp;
				}
			}
			else
			{
				for (int j=1;j+B[i]-1<=N;j++)
				{
					f[i][j] = -sum(j,B[i]);
					LL tmp = -INF;
					for (int k=j+1;k+B[i+1]<j+B[i];k++)
					{
						printf("%d %d\n",i,j,k);
						tmp=max(tmp,f[i+1][k]);
					}
					f[i][j]+=tmp;
				}
			}
			printf("%d:\n",i);
			for (int j=1;j<=N;j++)printf("%d ",f[i][j]);
			puts("");
			
		}
		LL ans = 0;
		for (int i=1;i<=N-B[1]+1;i++)ans=max(ans,f[1][i]);
		printf("%lld\n",ans);
	}
}
