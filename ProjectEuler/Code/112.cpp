#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int d[20],len;

bool inc()
{
	for (int i=2;i<=len;i++)
	if (d[i] < d[i-1]) return false;
	return true;
}

bool dec()
{
	for (int i=2;i<=len;i++)
	if (d[i] > d[i-1]) return false;
	return true;
}

bool check(LL x)
{
	len = 0;
	while(x)
	{
		d[++len] = x % 10;
		x /= 10;
	}
	return inc() || dec();
} 

int main()
{
	LL cnt = 0;
	for (LL i=1;;i++)
	{
		cnt += check(i);
		if (i == cnt * 100)
		{
			printf("%lld\n",i);
			break;
		}
	}
} 
