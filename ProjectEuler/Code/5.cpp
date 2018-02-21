#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL gcd(LL x,LL y){return y==0?x:gcd(y,x%y);}
int main()
{
	LL ans = 1;
	for (int i=1;i<=20;i++)
	{
		LL g = gcd(ans,i);
		ans = ans / g * i;
	}
	printf("%lld\n",ans);
}
