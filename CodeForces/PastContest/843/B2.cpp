#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,start,x,value,nxt;
int cnt,askcnt = 0;
int mi = 1e9 + 7, pos;

void ask(int now)
{
	cnt++;
	printf("? %d\n",now);
	fflush(stdout);
	scanf("%d%d",&value,&nxt);
}

int randseq[50010];
int Node;

void print(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}

int gen()
{
	return randseq[++Node];
}

int maxv = -1,maxpos;
int biu = 1000;

int main()
{
	cnt = 0;
	srand(23333);
	scanf("%d%d%d",&N,&start,&x);
	ask(start);
	if (value >= x)
	{
		print(value);
		return 0;
	}
	maxv = value;
	maxpos = start;
	for (int i=1;i<=N;i++)randseq[i] = i;
	random_shuffle(randseq+1,randseq+N+1);
	int N1 = min(biu,N), N2 = 1997 - N1;
	int mi = 1e9;
	for (int i=1;i<=N1;i++)
	{
		int nowpos = gen();
		ask(nowpos);
		if (value < x && value > maxv)
		{
			maxv = value;
			maxpos = nowpos;
		}
		else mi = min(mi,value);
	}
	int nowpos = maxpos;
	//printf("fuck %d\n",nowpos);
	for (int i=1;i<=N2;i++)
	{
		ask(nowpos);
		if (value >= x)
		{
			print(value);
			return 0;
		}
		if (nxt == -1)
		{
			print(-1);
			return 0;
		}
		nowpos = nxt;
	}
	assert(cnt <= 1999);
	print(mi);
}
