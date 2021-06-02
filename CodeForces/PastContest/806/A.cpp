#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL x,y,p,q;
		cin>>x>>y>>p>>q;
		LL ans;
		if (p==q && x!=y) {puts("-1");continue;}
		if (p==0 && x!=0) {puts("-1");continue;}
		//Min X+d/Y+d = p/q
		if (x*q == p*y) {puts("0");continue;}
		ans = -1;
		ans = max(x/p + (x%p != 0), (y-x)/(q-p) + ((y-x)%(q-p) != 0));
		cout<<ans*q-y<<endl;
	}
}
