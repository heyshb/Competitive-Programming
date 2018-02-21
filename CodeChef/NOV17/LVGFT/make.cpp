#include <bits/stdc++.h>

using namespace std;

int rd(int L,int R)
{
	return L + rand() % (R - L + 1);
}

int main()
{
	freopen("LVGFT.in","w",stdout);
	int T = 10, N = 200, M = 500;
	printf("%d\n",T);
	srand(time(0));
	while(T--)
	{
		N = rd(1,5);
		printf("%d %d\n",N,M);
		for (int i=2;i<=N;i++)printf("%d %d\n",i,rd(1,i-1));
		for (int i=1;i<=M;i++)printf("%d %d\n",rd(1,2),rd(1,N));
	}
}
