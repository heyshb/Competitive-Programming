#include <bits/stdc++.h>

using namespace std;

int f[110][10];

int main()
{
	int N;
	scanf("%d",&N);
	memset(f,0,sizeof(f));
	for (int i=0;i<=N;i++)
		for (int j=0;j<10;j++)f[i][j] = -1000000;
	f[0][0] = 0;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<10;j++)
			f[i+1][j] = f[i][j];
		int s;
		scanf("%d",&s);
		for (int j=0;j<10;j++)
		{
			int nxt = (j+s)%10;
			f[i+1][nxt] = max(f[i+1][nxt],f[i][j] + s);
			//printf("%d ",f[i][j]);
		}
		//puts("");
	}
	int ans = 0;
	for (int i=1;i<10;i++) ans = max(ans,f[N][i]);
	printf("%d\n",ans);
}
