#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL cost(LL x)
{
	return x*(x-1)/2;
}

int main()
{
	int N;
	scanf("%d",&N);
	if (N == 0)
	{
		puts("a");
		return 0;
	}
	char c = 'a';
	while(N)
	{
		int cnt = 0;
		while(cost(cnt+1) <= N) cnt++;
		N -= cost(cnt);
		for (int i=1;i<=cnt;i++)printf("%c",c);
		c++;
	}
}
