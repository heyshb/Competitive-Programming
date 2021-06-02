#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL H,W,h,w;
LL ans[510][510];

int main()
{
	scanf("%lld%lld%lld%lld",&H,&W,&h,&w);
	LL sum = 0;
	for (int i=1;i<=H;i++)
		for (int j=1;j<=W;j++)
		{
			if (i%h==0 && j%w==0)
				ans[i][j] = -(h*w-1)*2LL*max(H,W)-1;
			else
				ans[i][j] = 2LL*max(H,W);
			sum += ans[i][j];
		}
	if (sum > 0)
	{
		puts("Yes");
		for (int i=1;i<=H;i++)
			for (int j=1;j<=W;j++)printf("%lld%c",ans[i][j]," \n"[j==W]);
	}
	else puts("No");
}
