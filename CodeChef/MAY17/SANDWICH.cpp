#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL pow_mod(LL a,LL x,LL P)
{
	LL res = 1;
	while(x)
	{
		if (x&1)
			res = res*a%P;
		a = a*a%P;
		x>>=1;
	}
	return res;
}

LL C(LL N,LL P,LL pk)
{
	if (!N) return 1;
	LL i,j,k,res = 1;
	for (i=2;i<=pk;i++)
		if (i%P > 0)
			res = res*i%pk;
	res = pow_mod(res,N/pk,pk);
	for (k=N%pk,i=2;i<=k;i++)
		if (i%P > 0)
			res = res*i%pk;
	return res*C(N/P,P,pk)%pk;
}

LL rev(LL a,LL b)
{
	if (!a) return 0;
	LL y = 0,x = 1, r = a%b,q,t,mm = b;
	if (r < 0)
		r += b;
	while(b % r > 0)
	{
		a = b;
		b = r;
		q = a/b;
		r = a%b;
		t = x;
		x = y - x*q;
		y = t;
	}
	if (r!=1) return 0;
	if (x < 0) x += mm;
	return x;
}

LL calc(LL N,LL M,LL P,LL pi,LL pk)
{
	LL i,j,k = 0, a,b,c,ans;
	a = C(N,pi,pk);
	b = C(M,pi,pk);
	c = C(N-M,pi,pk);
	for (i=N;i;i/=pi) k += i/pi;
	for (i=M;i;i/=pi) k -= i/pi;
	for (i=N-M;i;i/=pi) k -= i/pi;
	ans = a*rev(b,pk)%pk;
	ans = ans*rev(c,pk)%pk;
	ans = ans*pow_mod(pi,k,pk)%pk;
	ans = ans*(P/pk)%P*rev(P/pk,pk)%P;
	return ans;
}

LL calcC(LL N,LL M,LL P)
{
	if (N < M) return 0;
	LL i,j,k,x,res = 0;
	//printf("Solve %lld %lld\n",N,M); 
	for (x=P,i=2;x>1;i++)
	if (x%i==0)
	{
		for (k=1;x%i==0;x/=i)
			k*=i;
		res = (res + calc(N,M,P,i,k)) % P; 
	}
	return res;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL N,K,R,ans1,ans2;
		int M;
		scanf("%lld%lld%d",&N,&K,&M);
		ans1 = (N+K-1)/K;
		LL D = ans1 * K - N;
		ans2 = calcC(D + ans1 - 1, ans1 - 1, M);
		printf("%lld %lld\n",ans1,ans2);
	}
}
