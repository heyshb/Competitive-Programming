#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,t,k,d;
	scanf("%d%d%d%d",&n,&t,&k,&d);
	int t1,t2;
	for (int i=1;i<=1000000;i++)
	if ((i/t) * k >= n)
	{
		t1 = i;
		break;
	}
	if (t1 <= d)
	{
		puts("NO");
		return 0;
	}
	for (int i=d;i<=1000000;i++)
	if ((i/t)*k + ((i-d)/t)*k >= n)
	{
		t2 = i;
		break;
	}
	puts(t1<=t2?"NO":"YES");
}
