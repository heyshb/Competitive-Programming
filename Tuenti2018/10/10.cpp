#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;
bool ok[1010][1010];
int N,M;
LL f[1010][1010];

LL calc(int L,int R,int dep)
{
	//for (int i=1;i<=dep;i++)printf(" ");
	//printf("solve %d %d\n",L,R);
	if (f[L][R] != -1) return f[L][R];
	if (L > R)
	{
		assert(L == R + 1);
		return 1;
	}
	LL ret = 0;
	for (int i=L+1;i<=R;i+=2)
	if (ok[L][i])
	{
		ret += calc(L+1,i-1,dep+1) * calc(i+1,R,dep+1);
		ret %= MOD;
	}
	return f[L][R] = ret;
}

int main()
{
	freopen("10_submit.in","r",stdin);
	freopen("10_submit.out","w",stdout);
	int T,_=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for (int i=1;i<=N+1;i++)
			for (int j=1;j<=N+1;j++)ok[i][j] = true,f[i][j] = -1;
		while(M--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u++;
			v++;
			ok[u][v] = ok[v][u] = false;
		}
		if (N % 2 != 0)
		{
			printf("Case #%d: 0\n",++_);
			continue;
		}
		LL ans = 0;
		for (int i=2;i<=N;i+=2)
		if (ok[1][i])
		{
			//printf("fuck %d %d %d %d\n",2,i-1,i+1,N);
			ans = ans + calc(2,i-1,0) * calc(i+1,N,0);
			ans %= MOD;
		}
		printf("Case #%d: %lld\n",++_,ans);
	}
}
