#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

char s[110][110]; 
int d[110][3];

int tp(char x)
{
	if (x=='#' || x=='*' || x=='&') return 2;
	if (x>='a' && x<='z') return 1;
	if (x>='0' && x<='9') return 0;
	return -1;
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)scanf("%s",s[i]);
	for (int i=1;i<=N;i++)
		for (int j=0;j<3;j++)d[i][j] = 100000;
	for (int i=1;i<=N;i++)
	{
		for (int j=0;j<M;j++)
		{
			int t = tp(s[i][j]);
			if (t==-1) continue;
			d[i][t] = min(d[i][t],j);
			d[i][t] = min(d[i][t],M-j);
		}
	}
	int ans = 100000000;
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
		if (j!=i)
			for (int k=1;k<=N;k++)
			if (k!=i && k!=j)
				ans = min(ans,d[i][0]+d[j][1]+d[k][2]);
	printf("%d\n",ans);
}
