#include <bits/stdc++.h>

using namespace std;

int fd[1010][1<<10][24],fh[1010][1<<10][24];
vector<int>e[1010];
const int INF = 1000000000;

void update(int &x,int &y,int ux,int uy)
{
	if (ux<x || (ux==x && uy<y))
	{
		x = ux;
		y = uy;
	}
}

void dfs(int x)
{
	int M = e[x].size();
	
	for (int i=0;i<M;i++)dfs(e[x][i]);
	
	for (int i=0;i<(1<<M);i++)
		for (int j=0;j<24;j++)
		fd[x][i][j] = fh[x][i][j] = INF; 
}

int main()
{
}
