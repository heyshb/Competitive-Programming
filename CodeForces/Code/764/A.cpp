#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int L[100010],R[100010];
int C[100010];
vector<int>e[100010];
bool vis[100010];

bool dfs(int x,int fa,int co)
{
	//printf("DFS %d %d %d\n",x,fa,co);
	if (C[x]!=co) return false;
	for (int i=0;i<e[x].size();i++)
	{
		int y=e[x][i];
		if (y==fa) continue;
		if (!dfs(y,x,co)) return false;
	}
	return true;
}

bool check(int root)
{
	//printf("Check %d\n",root);
	for (int i=0;i<e[root].size();i++)
	{
		int x = e[root][i];
		if (!dfs(x,root,C[x])) return false;
	}
	return true;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<N;i++)
	{
		scanf("%d%d",&L[i],&R[i]);
		e[L[i]].push_back(R[i]);
		e[R[i]].push_back(L[i]);
	}
	for (int i=1;i<=N;i++)scanf("%d",&C[i]);
	for (int i=1;i<N;i++)
	if (C[L[i]] != C[R[i]])
	{
		if (check(L[i]))
		{
			printf("YES\n%d\n",L[i]);
			return 0;
		}
		if (check(R[i]))
		{
			printf("YES\n%d\n",R[i]);
			return 0;
		}
		break;
	}
	if (check(1))
	{
		printf("YES\n%d\n",1);
		return 0;
	}
	puts("NO");
}
