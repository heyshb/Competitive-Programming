#include <bits/stdc++.h>

using namespace std;

char s[310];
int f[310][310][310];
bool same[310][310][310];

void update(int x,int y,int z,int a,int b,int c)
{
	f[a][b][c] = min(f[a][b][c],f[x][y][z] + 1);
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%s",s+1);
		int N = strlen(s+1);
		memset(same,false,sizeof(same));
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
			same[i][j][1] = (s[i] == s[j]);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				for (int k=2;k<=N;k++)
				if (i+k-1<=N && j+k-1<=N)
				{
					same[i][j][k] = (same[i][j][k-1] && s[i+k-1]==s[j+k-1]);
				}
		/*
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				for (int k=1;k<=N;k++)if (same[i][j][k]) printf("%d %d %d\n",i,j,k);*/
		int ans = 10000000;
		for (int i=0;i<=N;i++)
			for (int j=0;j<=N;j++)
				for (int k=0;k<=N;k++)f[i][j][k] = 10000000;
		
		f[0][0][0] = 0;
		for (int i=0;i<=N;i++)
		{
			int tmp = 10000000;
			for (int j=0;j<=i;j++)
				for (int k=j;k<=i;k++)
					tmp = min(tmp,f[i][j][k]);
			for (int j=0;j<=i;j++)
				for (int k=j;k<=i;k++)
				f[i][j][k] = min(f[i][j][k],tmp + 1);
			for (int j=0;j<=i;j++)
				for (int k=j;k<=i;k++)
				{
					//printf("f[%d][%d][%d] = %d\n",i,j,k,f[i][j][k]);
					update(i,j,k,i+1,j,k);
					int len = k - j + 1;
					if (same[i+1][j][len])
						update(i,j,k,i+len,j,k);
				}
			
			if (i == N) ans = min(ans,tmp);
		}
		
		printf("Case #%d: %d\n",_,ans); 
	}
}
