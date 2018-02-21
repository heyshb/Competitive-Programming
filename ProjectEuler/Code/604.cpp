#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL phi(LL x)
{
	LL res = 1;
	for (LL i=2;i*i<=x;i++)
	{
		if (x%i==0)
		{
			x/=i;
			res*=i-1;
			while(x%i==0)
				x/=i,res*=i;
		}
	}
	if (x>1) res*=x-1;
	return res;
}

int main()
{
	LL n = 1e18;
	LL i,a,b;
	i = 1;
	a = 1;
	b = 0;
	while(true)
	{
		//printf("%lld %lld %lld\n",i,a,b);
		LL j,z;
		j = i+1;
		z = phi(j);
		if (b+(z*j)/2 > n) break;
		i = j;
		a = a+z;
		b = b+(z*j)/2;
	}
	printf("%lld\n",a+(2*(n-b))/(i+1));
}
