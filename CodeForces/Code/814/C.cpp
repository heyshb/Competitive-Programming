#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
char s[1510];
int f[26][1510][1510];
int ans[26][1510];

int main()
{
	scanf("%d",&N);
	scanf("%s",s+1);
	memset(f,0,sizeof(f));
	memset(ans,0,sizeof(ans));
	for (int c=0;c<26;c++)
	{
		for (int i=1;i<=N;i++)
		{
			char ch = 'a' + c;
			if (s[i] == ch)
			{
				for (int j=0;j<=i;j++)
					f[c][i][j] = f[c][i-1][j] + 1;
			}
			else
			{
				f[c][i][0] = 0;
				for (int j=1;j<=i;j++)
					f[c][i][j] = f[c][i-1][j-1] + 1;
			}
		}
		ans[c][0] = 0;
		for (int i=1;i<=N;i++)
			ans[c][0] = max(ans[c][0],f[c][i][0]);
		for (int j=1;j<=N;j++)
		{
			ans[c][j] = ans[c][j-1];
			for (int i=1;i<=N;i++)
				ans[c][j] = max(ans[c][j],f[c][i][j]);
		}
	}
	int Q;
	scanf("%d",&Q);
	char tmp[2];
	int v;
	while(Q--)
	{
		scanf("%d",&v);
		scanf("%s",tmp);
		printf("%d\n",ans[tmp[0] - 'a'][v]);
	}
}
