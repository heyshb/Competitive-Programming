#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL up = 1LL << 32;

int main()
{
	//freopen("CHEFCOUN.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		printf("%d",3);
		LL S = 3;
		LL v = up / (N - 2);
		for (int i=2;i<N;i++)
			printf(" %lld",v);
		S += v * (N - 2);
		assert(S < up);
		S = up - S;
		if (S & 1) S++;
		printf("% lld\n",S / 2);
	}
}
