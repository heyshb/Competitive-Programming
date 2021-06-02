#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,B,C;
LL A[3010];
LL f1[3010][3010],f2[3010][3010];
LL g[3010][3010];
int pos[3010]; 
const LL INF = 1e17;

LL sq(LL x){return x*x;}

void print(LL arr[3010][3010])
{
	for (int i=0;i<=B;i++)
	{
		for (int j=1;j<=N;j++)printf("%lld ",arr[i][j]);
		puts("");
	}
}

int main()
{
	freopen("FLOWERPO.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&B,&C);
		for (int i=1;i<=N;i++)scanf("%lld",&A[i]),pos[i] = i;
		for (int i=0;i<=B;i++)
			for (int j=1;j<=N;j++)
			{
				f1[i][j] = INF;
				f2[i][j] = INF;
				g[i][j] = INF;
			}
		f1[0][1] = 0;
		for (int i=1;i<=B;i++)
			for (int j=1;j<=N;j++)
				for (int k=1;k<=j;k++)
				f1[i][j] = min(f1[i][j],f1[i-1][k] + sq(A[k] - A[j]));
		//puts("f1:");print(f1);
		//puts("done");
		f2[0][N] = 0;
		for (int i=1;i<=B;i++)
			for (int j=N;j>=1;j--)
				for (int k=N;k>=j;k--)
				f2[i][j] = min(f2[i][j],f2[i-1][k] + sq(A[k] - A[j]));
		//puts("done");
		//puts("f2:");print(f2);
		g[0][C] = 0;
		for (int i=1;i<=B;i++)
		{
			for (int j=C;j<=N;j++)
				for (int k=C;k<=j;k++)
				g[i][j] = min(g[i][j],g[i-1][k] + sq(A[k] - A[j]));
			for (int j=C;j>=1;j--)
				for (int k=C;k>=j;k--)
				g[i][j] = min(g[i][j],g[i-1][k] + sq(A[k] - A[j]));
		}
		//puts("g:");print(g);
		//puts("done");
 		
		LL ans = INF;
		for (int i=0;i<B;i++)
			for (int j=1;j<=N;j++)
			{
				int p1 = j,p2 = j;
				while(true)
				{
					ans = min(ans,g[i][j] + max(sq(A[j] - A[p2]),sq(A[j] - A[p1])) + f1[B-i-1][p1] + f2[B-i-1][p2]);
					if (p1 == 1 && p2 == N) break;
					
					if (p1 == 1) p2++;
					else if (p2 == N) p1--;
					else if (A[j] - A[p1-1] < A[p2+1] - A[j]) p1--;
					else p2++;
				}
			}
		printf("%lld\n",ans);
	}
}
