#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K;
LL H[100010],H0[100010];
LL f[100010][51];
int head,tail,q[100010];

LL g(int i,int k)
{
	return f[i][k] - H[k] * k;
}

LL ff(int i,int j,int k)
{
	//printf("g(%d,%d) + %lld * %d\n",i-1,k,H[k],j);
	return g(i-1,k) + H[k] * j;
}

LL solve()
{
	puts("solve!!!!!!!!!!!");
	for (int i=N-1;i>=1;i--)H[i] = min(H[i],H[i+1]);
	for (int i=1;i<=N;i++)printf("%lld ",H[i]);puts("");
	LL mi = 10000000;
	for (int i=1;i<=N;i++)
	{
		//f[0][i] = (i-1) * H[1];
		f[0][i] = 0;
	}
	H[0] = 0;
	for (int k=1;k<=K;k++)
	{
		q[head = tail = 1] = 0;
		f[k][0] = 0;
		for (int i=1;i<=N;i++)
		{
			while(head < tail && ff(k,q[head],i) < ff(k,q[head+1],i)) head++;
			//printf("%d %d from %d\n",k,i,q[head]);
			f[k][i] = ff(k,i,q[head]);
			//printf("f[%d][%d]=%lld\n",k,i,f[k][i]);
			q[++tail] = i;
		}
	}
	LL res = 0;
	for (int k=0;k<=K;k++)
		for (int i=1;i<=N;i++)
		{
			res = max(res,f[k][i] + H[i] * (N - i + 1));
		}
	//printf("%lld\n",res);
	return res;
}

int main()
{
	freopen("WEA.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&K);
		K++;
		for (int i=1;i<=N;i++)scanf("%lld",&H[i]),H0[i] = H[i];
		LL ans = solve();
		for (int i=1;i<=N;i++)H[i] = H0[i];
		reverse(H+1,H+N+1);
		ans = max(ans,solve());
		printf("%lld\n",ans);
	}
}
