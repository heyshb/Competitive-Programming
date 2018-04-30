#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M,I;
vector<int>e[100010];
int match[1010];
bool vis[1010];

bool find(int x)
{
	for (auto t:e[x])
	if (!vis[t])
	{
		vis[t] = true;
		if (match[t] == 0 || find(match[t]))
		{
			match[t] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("11_submit.in","r",stdin);
	freopen("11_submit.out","w",stdout);
	int T,_=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&M,&I);
		int P = max(N,M);
		for (int i=1;i<=P;i++)e[i].clear(),match[i] = 0;
		for (int i=1;i<=I;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u++;
			v++;
			e[u].push_back(v);
		}
		int ans = N + M;
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=P;j++)vis[j] = false;
			ans -= find(i);
		}
		printf("Case #%d: %d\n",++_,ans);
	}
} 
