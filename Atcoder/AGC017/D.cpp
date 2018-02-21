#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int>e[100010];
int N;
bool vis[100010];
int sg[100010];

int dfs(int x,int f)
{
	sg[x] = 0;
	for (auto t:e[x])
	if (t!=f)
		sg[x] ^= (dfs(t,x)+1);
	return sg[x];
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<N;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	printf(dfs(1,0)?"Alice":"Bob");
}
