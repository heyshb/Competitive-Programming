#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f[10010];

int main()
{
	LL x;
	scanf("%I64d",&x);
	f[1] = 2;
	f[0] = 1;
	int cnt = 1;
	for (int i=2;i<=100;i++)
	{
		f[i] = f[i-1] + f[i-2];
		//printf("%I64d\n",f[i]);
		cnt++;
	}
	for (int i=1;i<=cnt;i++)
	if (f[i]>x)
	{
		printf("%d\n",i-1);
		return 0;
	}
}
