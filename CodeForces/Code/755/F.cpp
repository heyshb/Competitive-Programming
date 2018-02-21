#include <bits/stdc++.h>

using namespace std;

int N,K;
int a[1000010];
bool vis[1000010];
vector<int>com;

void dfs(int x,int S)
{
	vis[x]=true;
	if (vis[a[i]])
	{
		com.push_back(S);
		return;
	}
	else dfs(a[i],S+1);
}

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=N;i++)
	if (!vis[i]) dfs(i,1);
	int MIN,MAX;
	
}
