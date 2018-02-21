#include <bits/stdc++.h>

using namespace std;

bool ok[2000010];
#define N 2000000
int main()
{
	
	memset(ok,true,sizeof(ok));
	typedef long long LL;
	LL ans = 0;
	for (int i=2;i<=N;i++)
	{
		if (ok[i]) ans+=i;
		for (int j=2*i;j<=N;j+=i)ok[j] = false;
	} 
	printf("%lld\n",ans);
}
