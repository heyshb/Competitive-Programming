#include <bits/stdc++.h>

using namespace std;

void rd(int x)
{
	for (int i=1;i<=x;i++)
		printf("%d",rand()%10);
}

int main()
{
	freopen("KILLER.in","w",stdout);
	puts("5");
	const int N = 5;
	srand(time(0));
	for (int C=1;C<=5;C++)
	{
		printf("%d\n",N);
		for (int i=1;i<=N;i++)
		{
			if (rand()%2) printf("-");
			rd(12);
			printf(" ");
			rd(5);
			puts("");
		}
		for (int i=1;i<N;i++)
			printf("%d %d\n",i,i+1);
	}
}
