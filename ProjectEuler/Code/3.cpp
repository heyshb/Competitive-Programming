#include <bits/stdc++.h>

using namespace std;


typedef long long LL;

bool isprime(int x)
{
	for (int i=2;i*i<=x;i++)
	if (x%i==0) return false;
	return true;
}

LL maxfac(LL x)
{
	LL res = -1;
	
	for (LL i=2;i*i<=x;i++)
	{
		if (isprime(i))
		{
			while(x%i==0)
			{
				printf("%lld\n",i);
				x/=i;
				res = max(res,i);
			}
		}
	}
	res = max(res,x);
	return res;
}

int main()
{
	printf("%lld\n",maxfac(600851475143LL));
}
