#include <bits/stdc++.h>
#define INF 50000000
using namespace std;

typedef long long LL;

int main()
{
	int N,MAX = INF , MIN = -INF;
	scanf("%d",&N);
	int S = 0, lastc = 0;
	while(N--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		S += lastc;
		if (d==1) MIN = max(MIN, 1900-S);
		else MAX = min(MAX, 1899-S);
		//printf("%d %d\n",MIN,MAX);
		lastc = c;
	}
	S += lastc; 
	if (MAX==INF) puts("Infinity");
	else if (MAX < MIN) puts("Impossible");
	else printf("%d\n",MAX + S);
}
