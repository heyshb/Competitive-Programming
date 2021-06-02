#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int>e[200010]; 
int N,root;
int d[200010];

int dfs(int x,int f)
{
	int v1 = -1, v2 = -1;
	for (int i=0;i<e[x].size();i++)
	if (e[x][i] != f)
	{
		int to = e[x][i];
		int tmp = (d[to]==1?0:dfs(to,x));
		if (tmp==v1 || tmp==v2) continue;
		if (v1==-1)
			v1 = tmp+1;
		else
		{
			if (v2==-1)
			{
				v2 = tmp+1;
				if (root == -1)
				{
					root = x;
				}
			}
			else return -1;
		}
	}
	return v1;
}

int main()
{
	scanf("%d",&N);
	if (N<=3)
	{
		printf("%d\n",N-1);
		return 0;
	}
	for (int i=0;i<N-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	root = -1;
	int res = dfs(1,0);
	if (root == -1)
		printf("%d\n",)
}
