#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N,L,R;
int v[200010],cnt;

LL calc(LL x)
{
	LL tmp = 1;
	while(tmp-1<x) tmp=tmp*2LL;
	return tmp-1;
}

LL gao(LL x,LL L,LL R)
{
	if (L>R) return 0;
	if (x<2) return x;
	LL half = calc(x/2);
	if (R<=half)
		return gao(x/2,L,R);
	else if (L>=half+2)
		return gao(x/2,L-half-1,R-half-1);
	else
		return gao(x/2,L,half)+gao(x/2,1,R-half-1)+x%2;
}

int main()
{
	scanf("%I64d%I64d%I64d",&N,&L,&R);
	printf("%I64d\n",gao(N,L,R));
}
