#include <bits/stdc++.h>

using namespace std;

int N;
int a[210][110];
int ans[110][110];
int x[10010],y[10010];
int dia[110];

int main()
{
	//freopen("B1.in","r",stdin);
	scanf("%d",&N);
	for (int i=1;i<=2*N;i++)
		for (int j=1;j<=N;j++)
		{
			scanf("%d",&a[i][j]);
			if (!x[a[i][j]])
				x[a[i][j]] = j;
			else
				y[a[i][j]] = j;
		}
	for (int i=1;i<=N*N;i++)
	if (x[i] == y[i]) dia[x[i]] = i;
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=2*N;j++)
		if (a[j][i] == dia[i] && ans[1][i] != a[j][1])
		{
			for (int k=1;k<=N;k++)
				ans[i][k] = a[j][k];
			break;
		}
	}
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			printf("%d%c",ans[i][j]," \n"[i==N&&j==N]);
	
}
