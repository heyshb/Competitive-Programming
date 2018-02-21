#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int check(LL x)
{
	int len = 0;
	while(x>1)
	{
		len++;
		if (x&1) x = x*3 + 1;
		else x/=2;
	}
	return len;
}

int main()
{
	int ans = 0, maxi;
	for (int i=1;i<=1000000;i++)
	{
		int V = check(i);
		if (V > ans)
		{
			ans = V;
			maxi = i;
		}
	}
	printf("%d %d\n",maxi,ans);
}
