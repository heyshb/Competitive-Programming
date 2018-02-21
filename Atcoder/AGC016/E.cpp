#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool lead[810][810];
int N,M;

int live(int x)
{
	return 2*x - 1;
}

int die(int x)
{
	return 2*x;
}

void cpy(int x,int y)
{
	//printf("cpy %d %d\n",x,y);
	lead[x][y] = 1;
	for (int i=1;i<=2*N;i++)
		lead[x][i] |= lead[y][i];
}

void pt(int x)
{
	if (x%2)
		printf("Live ");
	else
		printf("Die ");
	printf("%d",(x+1)/2);
}

void print()
{
	for (int i=1;i<=2*N;i++)
		for (int j=1;j<=2*N;j++)
		if (lead[i][j])
		{
			pt(i);
			printf("--->");
			pt(j);
			puts("");
		}
}

void addedge(int x,int y)
{
	if (lead[live(x)][die(y)])
	{
		cpy(live(x),die(x));
		cpy(live(y),die(y));
	}
	else
	{
		for (int i=1;i<=2*N;i++)if (lead[i][die(x)])cpy(i,die(y));
		for (int i=1;i<=2*N;i++)if (lead[i][die(y)])cpy(i,die(x));
		for (int i=1;i<=2*N;i++)if (lead[i][die(x)])cpy(i,die(y));
		cpy(live(x),die(y));
		cpy(live(y),die(x));
		//cpy(die(x),live(y));
		//cpy(die(x),die(y));
		
		//for (int i=1;i<=2*N;i++)if (lead[i][die(x)])cpy(i,die(y));
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	memset(lead,false,sizeof(lead));
	for (int i=1;i<=M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		print();
	}
	int ans = 0;
	for (int i=1;i<=N;i++)
	if (!lead[live(i)][die(i)])
		for (int j=i+1;j<=N;j++)
			if (!lead[live(i)][die(j)] && !lead[live(j)][die(i)] && !lead[live(j)][die(j)])
			{
				printf("OK %d %d\n",i,j);
				ans++;
			}
	//assert(ans%2==0);
	printf("%d\n",ans);
}
