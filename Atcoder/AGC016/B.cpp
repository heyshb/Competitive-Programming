#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int a[100010];
int mi,ma,cntmi,cntma;

int main()
{
	mi = 100000000;
	ma = -1;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		mi = min(mi,a[i]);
		ma = max(ma,a[i]);
	}
	if (ma > mi+1) return 0*puts("No");
	cntmi = cntma = 0;
	for (int i=1;i<=N;i++)
	{
		if (a[i] != mi && a[i] != ma) return 0*puts("No");
		if (a[i] == mi)
			cntmi++;
		if (a[i] == ma)
			cntma++;
	}
	bool res = true;
	if (mi == ma)
	{
		res = (mi * 2 <= N) || (mi == N-1);
	}
	else //ma = mi + 1
	{
		//printf("%d %d\n",cntmi-1+1,mi);
		int nd = mi - (cntmi - 1);
		res = (nd*2 <= cntma && nd>0);
	}
	puts(res?"Yes":"No");
}
