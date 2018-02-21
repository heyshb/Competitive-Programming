#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool isprime(int x)
{
	for (int i=2;i*i<=x;i++)
	if (x%i==0) return false;
	return true;
}

int ans[11] = {0,0,1,1,2,1,2,1,2,2,2};

int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		if (x<11) printf("%d\n",ans[x]);
		else if (isprime(x)) puts("1");
		else if (x%2==0) puts("2");
		else if (isprime(x-2)) puts("2");
		else puts("3");
	}
}
