#include <bits/stdc++.h>

using namespace std;

int N;
int a[210][110];
int ans[110][110];
int x[10010],y[10010];
int ax[10010],ay[10010];

int main()
{
	freopen("B1.in","r",stdin);
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
	for (int i=1;i<=N*N;i++)printf("%d %d\n",x[i],y[i]);
	
	//for (int i=1;i<=N*N;i++)
	//if (x[i] == y[i])
	//	ax[i] = ay[i] = x[i];

	for (int i=1;i<=2*N;i++)
	{
		bool rev = false;
		for (int j=1;j<=N;j++)
		{
			if (ax[a[i][j]] && ax[a[i][j]] != ay[a[i][j]])
			{	
				rev |= (ax[a[i][j]] == y[a[i][j]]);
			}
			rev |= ans[x[a[i][j]]][y[a[i][j]]];
		}
		if (rev)
		{
			for (int j=1;j<=N;j++)
			{
				ax[a[i][j]] = y[a[i][j]];
				ay[a[i][j]] = x[a[i][j]];
				printf("set %d %d %d\n",a[i][j],y[a[i][j]],x[a[i][j]]);
			}
		}
		else
		{
			for (int j=1;j<=N;j++)
			{
				ax[a[i][j]] = x[a[i][j]];
				ay[a[i][j]] = y[a[i][j]];
				printf("set %d %d %d\n",a[i][j],x[a[i][j]],y[a[i][j]]);
			}
		}
		for (int j=1;j<=N;j++)
			ans[ax[a[i][j]]][ay[a[i][j]]] = a[i][j];
	}
	
	for (int i=1;i<=N*N;i++)ans[ax[i]][ay[i]] = i;
	
		
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			printf("%d%c",ans[i][j]," \n"[i==N&&j==N]);
	
}
