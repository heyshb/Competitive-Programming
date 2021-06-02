#include <bits/stdc++.h>

using namespace std;

int rd(int l,int r)
{
	return l + rand()%(r - l + 1);
}

int main()
{
	srand(time(0));
	freopen("SEG.in","w",stdout);
	int T = 10;
	printf("%d\n",T);
	int N = rd(100,1000),P = rd(1,10000),Q = rd(1,1000);
	while(T--)
	{
		printf("%d %d %d\n",N,P,Q);
		for (int i=1;i<=N;i++) printf("%d ",rd(1,10000));puts("");
		for (int i=1;i<=Q/64+2;i++)printf("%d ",rd(1,100));
		puts("");
	}
}
