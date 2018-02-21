#include <bits/stdc++.h>

using namespace std;

typedef long long LL; 

LL D;
LL p[18],s[18];
int len,lst;

LL calc(LL D,int now,bool fst)
{
	//printf("calc %lld %d %d\n",D,now,fst);
	if (now == lst)
		return D==0;
	LL sum = 0;
	for (LL i=-9;i<=9;i++)
	{
		LL nxtnd = D - LL(i) * p[now];
		LL mx = (s[now-1] - s[lst]) * 9LL;
		if (mx < 0) mx = -mx; 
		//printf("%lld: %lld %lld\n",i,nxtnd,mx);	
		if (nxtnd > mx || nxtnd < -mx) continue;
		//puts("wow");
		LL maxN = min(i+9,9LL);
		LL minN = max(i,0LL);
		if (fst) minN = max(minN,1LL);
		//printf("%lld~%lld\n",minN,maxN);
		LL tmp = maxN - minN + 1;
		sum += tmp * calc(nxtnd,now-1,0);
	}
	return sum;
}

int main()
{
	p[0] = 1;
	for (int i=1;i<=17;i++)p[i] = p[i-1] * 10LL;
	for (int i=1;i<=17;i++)p[i] = p[i] - 1;
	s[0] = 0;
	for (int i=1;i<=17;i++)s[i] = s[i-1] + p[i];
	scanf("%lld",&D);
	LL ans = 0;
	for (len=1;len<=1;len++)
	{
		lst = len/2;
		ans += calc(-D,len,1); 
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
}
