#include <bits/stdc++.h>

using namespace std;

char s[2][510];
int sum[2][510];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int N;
bool f[510][2];
int fa[1010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		scanf("%s",s[0] + 1);
		scanf("%s",s[1] + 1);
		memset(f,false,sizeof(f));
		for (int i=1;i<=N;i++)
			for (int j=0;j<=1;j++)
			{
				if (s[j][i] == '#')
				{
					if (s[j^1][i] == '#')
					{
					}
					else
					{
					}
				}
			}
		if (cnt <= 2)
			puts("yes");
		else
			puts("no");
	}
}
