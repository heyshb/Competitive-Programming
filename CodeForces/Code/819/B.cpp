#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
LL a[1000010];
LL cntsm[1000010],cntlg[1000010];
LL sumlg,sumsm;

int main()
{
	LL s = 0;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%I64d",&a[i]);
		LL d = LL(i) - a[i];
		if (d < 0)
		{
			d = -d;
			cntsm[d]++;
			sumsm++;
		}
		else
		{
			cntlg[d]++;
			sumlg++;
		}
		s += d;
	}
	for (int k=1;k<N;k++)
	{
		LL pos = N-k+1;
		LL lastnow = a[pos];
		if (lastnow > pos) 
	}
}
