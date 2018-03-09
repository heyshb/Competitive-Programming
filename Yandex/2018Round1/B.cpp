#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[200]; 
int tt[200];
int N,ans = 0;
int trans[200];
bool vis[200];

bool check()
{
	int now = 0;
	for (int i=0;i<N;i++)
	tt[i] = trans[s[i] - '0'];
	for (int i=0;i<N;i++)
	{
		if (tt[i] == now) now++;
	}
	return now==10;
}

void dfs(int x)
{
	if (x == 10)
	{
		ans += check();
		return;
	}
	for (int i=0;i<10;i++)
	if (!vis[i])
	{
		vis[i] = true;
		trans[x] = i;
		dfs(x + 1);
		vis[i] = false;
	}
}

int main()
{
	scanf("%s",s);
	N = strlen(s);
	memset(vis,false,sizeof(vis));
	dfs(0);
	printf("%d\n",ans);
}
