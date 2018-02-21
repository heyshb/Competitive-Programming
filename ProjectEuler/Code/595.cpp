#include <bits/stdc++.h>

using namespace std;

int ans = 0,ans2;
int dep = 0;

bool vis[100];
vector<int>v;

void dfs(int d)
{
	if (d==dep+1)
	{
		int cnt = 0;
		for (int i=0;i<dep-1;i++)
		if (v[i+1]==v[i]+1) cnt++;
		//for (int i=0;i<dep;i++)printf("%d",v[i]);
		//puts("");
		if (cnt == 1)
		{
			ans2++;
			for (int i=0;i<dep;i++)printf("%d",v[i]);
			puts("");
		}
		if (cnt == 0)ans++;
		return;
	}
	for (int i=1;i<=dep;i++)
	if (!vis[i])
	{
		v.push_back(i);
		vis[i] = true;
		dfs(d+1);
		vis[i] = false;
		v.pop_back();
	}
}

int main()
{
	for (dep = 1;dep<=5;dep++)
	{
		ans = 0;
		ans2 = 0;
		memset(vis,false,sizeof(vis));
		dfs(1);
		printf("%d %d %d\n",dep,ans,ans2);
	}
}
