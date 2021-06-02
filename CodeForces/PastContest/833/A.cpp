#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL A,B;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&A,&B);
		if (A == 1 && B == 1)
		{
			puts("Yes");
			continue;
		}
		if (A == 0 || B == 0)
		{
			if (A == B)
				puts("Yes");
			else
				puts("No");
			continue;
		}
		LL S = A * B;
		LL sq = LL(pow(S,0.333333333));
		while(sq*sq*sq < S) sq++;
		while(sq*sq*sq > S) sq--;
		//printf("%lld\n",sq);
		if (sq*sq*sq != S)
		{
			puts("No");
			continue;
		}
		if (A % sq == 0 && B % sq == 0)
			puts("Yes");
		else
			puts("No");
	}
}
