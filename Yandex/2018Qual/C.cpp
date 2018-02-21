#include <bits/stdc++.h>

using namespace std;

int N;
int ans = 0;
int a[10][10];

void dfs(int x,int y)
{
	if (x == N + 1)
	{
		ans++;
		return;
	}
	for (int i=1;i<=N;i++)
	{
		a[x][y] = i;
		if (y == N)
		{
			int S = 0;
			for (int j=1;j<=N;j++) S += a[x][j];
			if (S % N != 0) continue;
		}
		if (x == N)
		{
			int S = 0;
			for (int j=1;j<=N;j++) S += a[j][y];
			if (S % N != 0) continue;
		}
		int nx = x, ny = y + 1;
		if (ny == N + 1) 
		{
			nx = x + 1;
			ny = 1;
		}
		dfs(nx,ny);
	}
}

int main()
{
	scanf("%d",&N);
	dfs(1,1);
	printf("%d\n",ans);
}
