#include <bits/stdc++.h>
 
using namespace std;

typedef long long LL;

LL MOD = 1000000007;

LL phi(LL n)
{
    LL ret=1;
    for(LL i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n/=i,ret*=i-1;
            while(n%i==0) n/=i,ret*=i;
        }
    }
    if(n>1) ret*=n-1;
    return ret;
}

int main()
{
	LL N,K;
	scanf("%I64d%I64d",&N,&K);
	for (LL i=1;i<=(K+1)/2;i++)
	{
		if (N==1) break;
		N = phi(N);
	}
	N%=MOD;
	printf("%I64d\n",N);
}
