#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL gcd(LL a,LL b)
{
	return b==0?a:gcd(b,a%b);
}

bool check(LL q,LL b)
{
	if (q == 1) return true;
	LL g = gcd(q,b);
	if (g == 1) return false;
	while(q % g == 0) q /= g;
	return check(q,b);
}

int main()
{
	int Q;
	scanf("%d",&Q);
	LL p,q,b;
	while(Q--)
	{
		scanf("%lld%lld%lld",&p,&q,&b);
		int N = 0;
		LL g = gcd(p,q);
		p /= g;
		q /= g;
		if (check(q,b))
		{
			puts("Finite");
		}
		else
		{
			puts("Infinite");
		}
	}
}
