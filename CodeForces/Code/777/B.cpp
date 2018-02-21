#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
char s[1010];
int sum[2][10];
int v[2][1010];
int len[2];

int main()
{
	scanf("%d",&N);
	scanf("%s",s);
	for (int i=0;i<N;i++)sum[0][s[i]-'0']++;
	scanf("%s",s);
	for (int i=0;i<N;i++)sum[1][s[i]-'0']++;
	for (int i=0;i<2;i++)
	{
		len[i] = 0;
		for (int j=0;j<10;j++)
			for (int k=0;k<sum[i][j];k++)
			v[i][++len[i]] = j;
	}
	v[1][N+1] = -1;
	v[0][N+1] = -1;
	/*
	for (int i=0;i<2;i++)
	{
		for (int j=1;j<=N;j++)printf("%d",v[i][j]);
		puts("");
	}
	*/
	for (int i=1;i<=N;i++)printf("%d",v[0][i]);puts(""); 
	for (int i=1;i<=N;i++)printf("%d",v[0][i]);puts(""); 
	int now=1, ans=N;
	for (int i=1;i<=N;i++)
	{
		while(now<=N && v[1][now]<v[0][i])now++;
		if (v[1][now]>=v[0][i]) ans--;
	}
	printf("%d\n",ans);
	
	now=1;
	ans=0;
	for (int i=1;i<=N;i++)
	{
		while(now<=N && v[1][now]<=v[0][i])now++;
		if (v[1][now]>v[0][i]) ans++;
	}
	printf("%d\n",ans);
}
