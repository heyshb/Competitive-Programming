#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
LL C[100010],H[100010],dep[100010],f[100010];
vector<int>e[100010];

LL Gauss(LL A,LL B)
{
	return (A + B) * (B - A + 1) / 2; 
}

LL trans(int i,int u)
{
	return f[u] - H[u-1] + C[u-1] * C[u-1] * (u - i) +
		   C[u-1] * Gauss(N-(u-1), N-i);
}

int head,tail;
int q[100010];

#define TEST
int main()
{
	#ifdef TEST
		freopen("KILLER.in","r",stdin);
		//freopen("KILLER1.out","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)e[i].clear();
		for (int i=1;i<=N;i++)scanf("%lld%lld",&H[i],&C[i]);
		for (int i=1;i<N;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		f[N + 1] = 0;
		for (int i=N;i>=1;i--)
		{
			f[i] = 1e17;
			for (int j=i+1;j<=N+1;j++)
			{
				//printf("%d %d %lld\n",i,j,trans(i,j)); 
				f[i] = min(f[i],trans(i,j));
			}
			printf("%lld\n",f[i]);
		}
		printf("%lld\n",f[1]);
	}
}
