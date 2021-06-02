#include <bits/stdc++.h>

using namespace std;

struct event
{
	int x,y,t;
}e[250010];

bool cmp(event a,event b){return a.t<b.t;}

int N,M,K,Q;
int s[510][510];

bool broken(int TT)
{
	for (int i=0;i<=N;i++)
		for (int j=0;j<=M;j++)s[i][j] = 0;
	for (int i=1;i<=Q;i++)
	if (e[i].t <= TT)
		s[e[i].x][e[i].y] = 1;
	else
		break;
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		s[i][j] = s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	for (int i=K;i<=N;i++)
		for (int j=K;j<=M;j++)
		if (s[i][j] - s[i][j-K] - s[i-K][j] + s[i-K][j-K] == K*K) return true;
	return false;
}

int main()
{
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	int mt = 0;
	for (int i=1;i<=Q;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].t),mt = max(mt,e[i].t);
	sort(e+1,e+Q+1,cmp);
	int L = 0, R = mt;
	if (!broken(R)) return 0*puts("-1");
	while(L < R - 1)
	{
		int mid = (L + R) >> 1;
		if (broken(mid))
			R = mid;
		else
			L = mid;
	}
	printf("%d\n",R);
}
