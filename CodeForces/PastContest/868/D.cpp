#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int up = 14;
int pre[210][up+1];
int suc[210][up+1];
int len[210];
bool vis[210][up+1][1<<up];
int N,M;
char s[110][110];
int ans[210];

bool check(int num,int v)
{
	for (int i=0;i<(1<<v);i++)
	if (!vis[num][v][i]) return false;
	return true;
}

void uno(int x,int y,int z)
{
	len[z] = len[x] + len[y];
	ans[z] = max(ans[x],ans[y]);
	for (int i=1;i<=up;i++)
		for (int j=0;j<(1<<i);j++)
		{
			vis[z][i][j] |= vis[x][i][j];
			vis[z][i][j] |= vis[y][i][j];
		}
	for (int i=1;i<=up;i++)
	{
		if (i <= len[y])
			suc[z][i] = suc[y][i];
		else if (i <= len[x] + len[y])
			suc[z][i] = (suc[x][i-len[y]] << len[y]) + suc[y][len[y]];
		else
			suc[z][i] = -1;
			
		if (i <= len[x])
			pre[z][i] = pre[x][i];
		else if (i <= len[x] + len[y])
			pre[z][i] = (pre[x][len[x]] << (i - len[x])) + pre[y][i - len[x]];
		else
			pre[z][i] = -1;
	}
	for (int i=1;i<=up;i++)
	{
		for (int j=1;j<i;j++)
		{
			int k = i - j;
			if (suc[x][j] == -1 || pre[y][k] == -1) continue;
			vis[z][i][(suc[x][j] << k) + pre[y][k]] = true;
			//printf("gao %d %d\n",i,(suc[x][j] << k) + pre[y][k]);
		}
	}
    if (check(z,ans[z]+1)) ans[z]++;
}

int main()
{
	freopen("D.in","r",stdin);
	memset(vis,false,sizeof(vis));
	scanf("%d",&N);
	for (int i=1;i<=200;i++)
		for (int j=0;j<=up;j++)
			pre[i][j] = suc[i][j] = -1;
	for (int i=1;i<=N;i++)
	{
		scanf("%s",s[i] + 1);
		len[i] = strlen(s[i] + 1);
		for (int j=1;j<=min(up,len[i]);j++)
		{
			pre[i][j] = 0;
			for (int k=1;k<=j;k++)pre[i][j] = pre[i][j] * 2 + s[i][k] - '0';
			
			//printf("pre %d %d = %d\n",i,j,pre[i][j]);
			suc[i][j] = 0;
			for (int k=len[i]-j+1;k<=len[i];k++)suc[i][j] = suc[i][j] * 2 + s[i][k] - '0';
			//printf("suc %d %d = %d\n",i,j,suc[i][j]);
		}
		for (int j=1;j<=up;j++)
		{
			for (int k=1;k+j-1<=len[i];k++)
			{
				//printf("%d %d\n",j,k);
				int tmp = 0;
				for (int l=k;l<=k+j-1;l++)
					tmp = tmp * 2 + s[i][l] - '0';
				vis[i][j][tmp] = true;
				//printf("vis %d %d = true\n",j,tmp);
			}
		}	
		for (int j=1;j<=10;j++)
		if (!check(i,j))
		{
			ans[i] = j-1;
			break;
		}
	}
	scanf("%d",&M);
	for (int i=N+1;i<=N+M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		uno(a,b,i);
		printf("%d\n",ans[i]);
	}
}
