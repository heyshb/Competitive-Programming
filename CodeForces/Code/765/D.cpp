#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,f[100010];
int M,g[100010],h[100010];

int main()
{
	scanf("%d",&N);
	f[0] = -1;
	M = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&f[i]);
		if (f[i]<f[i-1])
		{
			puts("-1");
			return 0;
		}
		if (f[i]>f[i-1])
		{
			h[++M] = f[i];
		}
	}
	unique(f+1,f+N+1);
	printf("%d\n",M);
	for (int i=1;i<=N;i++)printf("%d ",lower_bound(f+1,f+M+1,h[i])-f);
	puts("");
	for (int i=1;i<=M;i++)printf("%d ",h[i]);
}
