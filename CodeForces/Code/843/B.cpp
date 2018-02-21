#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,start,x,value,nxt;
bool vis[50010];
int up = 1999;
int blk = 101,cnt,askcnt = 0;
int mi = 1e9 + 7, pos;

void ask(int now)
{
	up--;
	cnt++;
	printf("? %d\n",now);
	vis[now] = true;
	fflush(stdout);
	scanf("%d%d",&value,&nxt);
}

int randseq[50010];
int Node;

int gen()
{
	if (Node == N)
	{
		printf("! %d\n",mi);
		fflush(stdout);
		exit(0);
	}
	return randseq[++Node];
}

int main()
{
	srand(25252);
	scanf("%d%d%d",&N,&start,&x);
	for (int i=1;i<=N;i++)randseq[i] = i;
	random_shuffle(randseq+1,randseq+N+1);
	Node = 0;
	while(up)
	{
		int now = gen();
		if (vis[now]) continue;
		ask(now);
		if (value >= x)
		{
			mi = min(mi,value);
			continue;
		}
		cnt = 0;
		while(up && cnt < blk && nxt != -1 && !vis[nxt])
		{
			cnt++;
			up--;
			ask(nxt);
			if (value >= x)
			{
				mi = min(mi,value);
				break;
			}
		}
	}
	printf("! %d\n",mi);
	fflush(stdout);
}
