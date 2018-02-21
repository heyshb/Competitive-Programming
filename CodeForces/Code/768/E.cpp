#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int f[61][61],sg[61][61];
bool vis[100010];

int main()
{
	memset(vis,0,sizeof(f));
	for (int i=1;i<=60;i++)
	{
		for (int j=1;j<=i;j++)//The maximum number deletable this turn
		{
			for (int k=1;k<=j;k++)
				vis[sg[i-k][k-1]] = true;
			for (int k=0;k<=100000;k++)
				if (!vis[k])
				{
					sg[i][j] = k;
					break;
				}
			for (int k=1;k<=j;k++)
				vis[sg[i-k][k-1]] = false;
		}
	}
	/*
	for (int i=1;i<=10;i++)
	{
		for (int j=1;j<=i;j++)
		printf("%d ",sg[i][j]);
		puts("");
	}*/
	int N,res=0;
	scanf("%d",&N);
	while(N--)
	{
		int tmp;
		scanf("%d",&tmp);
		res^=sg[tmp][tmp];
	}
	puts(res?"NO":"YES");
}
