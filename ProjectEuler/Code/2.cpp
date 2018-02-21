#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c,ans=2;
	a = 1;
	b = 2;
	while(true)
	{
		c = a + b;
		if (c > 4000000) break;
		if (c%2==0) ans+=c;
		a = b;
		b = c;
	}
	printf("%d\n",ans);
}
