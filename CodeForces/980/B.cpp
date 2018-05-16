#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K;
bool hotel[10][1010];

void print()
{
	puts("YES");
	for (int i=1;i<=4;i++)
	{
		for (int j=1;j<=N;j++)if (hotel[i][j])printf("#");
		else printf(".");
		puts("");
	}
}

void putmid(int x,int y)
{
	hotel[x][(N+1)/2] = true;
	y--;
	int L,R;
	L = R = (N+1)/2;
	while(y)
	{
		hotel[x][--L] = true;
		hotel[x][++R] = true;
		y-=2;
	}
}

int main()
{
	scanf("%d%d",&N,&K);
	if (K == 0)
	{
		print();
		return 0;
	}
	bool change = false;
	if (K % 2) 
	{
		change = true;
		K++;
	}
	int x,y;
	for (int i=N-2;i>=1;i-=2)
	if (K - i > 0)
	{
		x = i;
		y = K - i;
		break;
	}
	putmid(2,x);
	putmid(3,y);
	if (change) hotel[2][(N+1)/2] = false;
	print();
}
