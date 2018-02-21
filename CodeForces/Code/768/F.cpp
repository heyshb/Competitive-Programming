#include <bits/stdc++.h>
#define MOD 1000000007 
#define UP 100000
using namespace std;

typedef long long LL;

LL fac[UP+10],inv[UP+10];
int f,w,h;

LL quick_pow(LL a,LL x)
{
	LL res = 1;
	while(x)
	{
		if (x&1) res = res*a % MOD;
		a = a*a % MOD;
		x>>=1;
	}
	return res;
}

LL C(LL N,LL M)
{
	if (N<M) return 0;
	return ((fac[N]*inv[M])%MOD)*inv[N-M]%MOD;
}

LL DIV(LL N,LL M)
{
	if (N<M) return 0;
	if (N==0 && M==0) return 1;
	return C(N-1,M-1);
}

int main()
{
	fac[0] = 1;
	for (int i=1;i<=UP;i++)fac[i] = fac[i-1]*LL(i)%MOD;
	inv[UP] = quick_pow(fac[UP],MOD-2);
	for (int i=UP-1;i>=0;i--)inv[i] = inv[i+1]*LL(i+1)%MOD;
	//printf("%I64d\n",DIV(0,0)); 
	scanf("%d%d%d",&f,&w,&h);
	if (w==0)
	{
		puts("1");
		return 0;
	}
	if (f==0)
	{
		if (w>h) puts("1");
		else puts("0");
		return 0;
	}
	LL P = 0, Q = 0;
	for (int i=1;i<=w;i++)
		for (int j=i-1;j<=i+1;j++)
		{
			if (j<1 || j>f) continue;
			LL tmp = DIV(w,i)*DIV(f,j)%MOD;
			if (i==j) tmp*=2LL;
			tmp%=MOD;
			Q = (Q + tmp) % MOD;
			LL mini = LL(w)-LL(i)*LL(h);
			mini %= MOD;
			if (mini<0 || mini>w) continue;
			tmp = DIV(mini,i)*DIV(f,j)%MOD;
			if (i==j) tmp*=2LL;
			tmp%=MOD;
			P = (P + tmp) % MOD;
			//printf("%d %d %I64d %I64d %I64d\n",i,j,mini,P,Q);
		}
	Q = quick_pow(Q,MOD-2);
	printf("%I64d\n",P*Q%MOD);
}
