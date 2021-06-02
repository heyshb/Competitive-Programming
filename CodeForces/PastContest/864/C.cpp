#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int a,b,f,k;
	scanf("%d%d%d%d",&a,&b,&f,&k);
	int now = b + f;
	if (b < f) return 0 * puts("-1");
	int ans = 0;
	for (int i=1;i<=k;i++)
	{
		int dis;
		if (i & 1)
			dis = 2*f;
		else
			dis = 2*(a-f);
		if (now < dis)
		{
			if (b < dis) return 0 * puts("-1");
			now = b;
			ans++;
		}
		now -= dis;
	}
	int dis = (k&1)?a-f:f;
	if (now < dis)
	{
		if (b < dis) return 0 * puts("-1");
		now = b;
		ans++;
	}
	now -= dis;
	printf("%d\n",ans);
}
