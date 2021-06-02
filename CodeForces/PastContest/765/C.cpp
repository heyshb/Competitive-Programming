#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int K,A,B;

int main()
{
	scanf("%d%d%d",&K,&A,&B);
	if (A<K && B<K)
	{
		puts("-1");
		return 0;
	}
	if (A<B) swap(A,B);
	if (B<K && A%K!=0) 
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",A/K+B/K);
}
