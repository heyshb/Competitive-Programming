#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<int>e[100];
bool a[100][100];
bool cli[1<<23];
int N,M;
int lowbit(int x){return x&-x;}
int lg[1<<23];
int f[1<<23];

int main()
{
	for (int i=0;i<22;i++)lg[1<<i] = i;
	scanf("%d",&N,&M);
	for (int i=0;i<N;i++)a[i][i] = true;
	for (int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		e[u].push_back(v);
		e[v].push_back(u);
		a[u][v] = a[v][u] = true;	
	}	
	cli[0] = true;
	for (int i=1;i<(1<<N);i++)
	{
		int u = lg[lowbit(i)];
		cli[i] = true;
		for (int j=0;j<N;j++)
		if (((1<<j) & i) && !a[u][j]) cli[i] = false;
		if (cli[i])
			f[i] = 0;
		else
			f[i] = 10000000;
	}
	printf("%d\n",f[(1<<N) - 1]);
}
