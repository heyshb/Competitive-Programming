#include <bits/stdc++.h>

using namespace std;

int rd(int L,int R)
{
	return L + rand() % (R - L + 1);
}

int main()
{
	int T = 10;
	freopen("POLY.in","w",stdout);
	printf("%d\n",T);
	srand(time(0));
	while(T--)
	{
		int N = rd(1,500);
		printf("%d\n",N);
		for (int i=1;i<=N;i++)printf("%d %d %d %d\n",rd(0,1000),rd(0,100000),rd(0,100000),rd(0,100000));
		int Q = rd(1,100);
		printf("%d\n",Q);
		for (int i=1;i<=Q;i++)printf("%d\n",rd(0,100000));
	}
}
