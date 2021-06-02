#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,A[110],D[110];
bool vis[110];

LL gcd(LL a,LL b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		D[A[i]]++;
	}
	LL ans = 1;
	for (int i=1;i<=N;i++)
	if (D[i]==0)
	{
		puts("-1");
		return 0;
	}
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=N;i++)
	if (!vis[i])
	{
		int cnt = 0,now = i;
		while(!vis[now])
		{
			vis[now]=true;
			now=A[now];
			cnt++;
		}
		if (cnt%2==0) cnt/=2;
		ans = ans/gcd(ans,cnt)*LL(cnt);
	}
	printf("%I64d\n",ans);
}
