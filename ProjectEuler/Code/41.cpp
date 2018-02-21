#include <bits/stdc++.h>

using namespace std;

int d,ans = 2143;
bool used[10];

bool check(int x)
{
	for (int i=2;i*i<=x;i++)if (x%i==0) return false;
	return true;
}

void dfs(int dep,int v)
{
	if (dep == d + 1)
	{
		if (check(v)) ans = max(ans,v);
		return;
	}
	for (int i=1;i<=d;i++)
	if (!used[i])
	{
		used[i] = true;
		dfs(dep+1,v*10+i);
		used[i] = false;
	}
}

int main()
{
	for (d=4;d<=9;d++)
	{
		memset(used,false,sizeof(used));
		dfs(1,0);
	}
	printf("%d\n",ans);
}
