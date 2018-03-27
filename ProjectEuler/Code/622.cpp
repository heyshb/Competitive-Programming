#include <bits/stdc++.h>

using namespace std;

int a[10000],b[10000],c[10000];

bool ok(int N)
{
	for (int i=1;i<=N;i++)if (a[i] != i) return false;
	return true;
}

int calc(int N)
{
	int ans = 0;
	for (int i=1;i<=N;i++)a[i] = i;
	while(true)
	{
		ans++;
		for (int i=1;i<=N/2;i++)b[i] = a[i];
		for (int i=1;i<=N/2;i++)c[i] = a[i+N/2];
		for (int i=1;i<=N/2;i++)
		{
			a[2*i-1] = b[i];
			a[2*i] = c[i];
		}
		if (ok(N)) break;
	}
	return ans;
}

typedef long long LL;

bool check(LL v,int x)
{
	LL tmp = 1;
	for (int i=1;i<x;i++)
	{
		tmp*=2LL;
		if ((tmp-1)%v==0)return false;
	}
	return true;
}

LL solve(int x)
{
	LL v = 1;
	for (int i=1;i<=x;i++)v=v*2;
	v--;
	LL ans=0;
	for (LL i=1;i*i<=v;i++)
	{
		if (i%100000000==0) puts("wow");
		if (v%i==0)
		{
			//printf("%lld %lld\n",i,v/i);
			if (check(i,x)) ans += i + 1;
			if (check(v/i,x)) ans += v/i + 1;
		}
	}
	return ans;
}

int main()
{
	//for (int i=2;i<=200;i+=2)printf("%d %d\n",i,calc(i));
	//printf("%lld\n",solve(8));
	printf("%lld\n",solve(60));
}
