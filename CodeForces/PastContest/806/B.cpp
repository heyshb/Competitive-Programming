#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int sum[6];
int T[121][6];
int score[6] = {500,1000,1500,2000,2500,3000};
int N;
int ans = 1000000008;
int type[6];

void dfs(int dep,int nowans)
{
	if (dep == 6)//all problem has been considered
	{
		double scorea,scoreb;
		for (int i=1;i<=5;i++)
		{
			if (T[1][i] != -1)
				scorea += score[type[i]] * (1-T[1][i]/250.0);
			if (T[2][i] != -1)
				scoreb += score[type[i]] * (1-T[2][i]/250.0);
		}
		if (scorea > scoreb + 1e-5)
			ans = min(ans,nowans);
	}
	for (int i=0;i<6;i++)
	{
		int minneed;
	}
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=5;j++)scanf("%d",&T[i][j]),sum[j]+=(T[i][j] != -1);
	dfs(1,0);	
	printf("%d\n",)
}
