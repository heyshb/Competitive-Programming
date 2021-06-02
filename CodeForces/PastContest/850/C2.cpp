#include <bits/stdc++.h>

using namespace std;

int sg[200][200];
bool vis[200]; 

int main()
{
	int N = 30, M = 30;
	sg[0][0] = 0;
	for (int i=0;i<=N;i++)
		for (int j=0;j<=M;j++)
		{
			memset(vis,false,sizeof(vis));
			for (int k=1;k<=max(i,j);k++)
			{
				int ii,jj;
				if (k<=i) ii = i-k; else ii = i;
				if (k<=j) jj = j-k; else jj = j;
				vis[sg[ii][jj]] = true;
			}
			for (int k=0;k<=10000;k++)
			if (!vis[k])
			{
				sg[i][j] = k;
				break;
			}
		}
	for (int i=0;i<=N;i++)
	{
		for (int j=0;j<=M;j++)printf("%2d ",sg[i][j]);
		puts(""); 
	}
}
