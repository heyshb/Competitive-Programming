#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
vector<int>fac[10010];
int ans[10010];
map<vector<int>,int>last;
int pre[10010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		int v;
		scanf("%d",&v);
		if (v == 0) continue;
		if (v < 0)
		{
			fac[i].push_back(-1);
			v = -v;
		}
		for (int j=2;j<=10000;j++)
		if (v % j == 0)
		{
			int ret = 0;
			while(v % j == 0)
			{
				ret ^= 1;
				v /= j;
			}
			if (ret) fac[i].push_back(j);
			if (v <= 1) break;
		}
		if (v > 1) fac[i].push_back(v);
		last[fac[i]] = -1;
	}
	for (int i=1;i<=N;i++)
	{
		pre[i] = last[fac[i]];
		last[fac[i]] = i;
	}
	for (int i=1;i<=N;i++)
	{
		int now = 0;
		for (int j=i;j<=N;j++)
		{
			if (pre[j] < i) now++;
			ans[now]++;
		}
	}
	for (int i=1;i<=N;i++)printf("%d%c",ans[i]," \n"[i==N]);
}
