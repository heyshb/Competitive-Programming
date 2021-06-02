#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL MOD;

LL Pow(LL a,LL b,LL P)
{
	assert(b >= 0);
	LL res = 1;
	for (;b;b>>=1,a=a*a%P)
		if (b&1) res = res*a%P;
	return res;
}

void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if (b==0) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=(a/b)*x;
}

LL inverse(LL A,LL N)
{
	LL d,x,y;
	exgcd(A,N,d,x,y);
	return (x+N)%N;
}

LL mul[1000010];

LL fac(LL N,LL P,LL PR)
{
	//printf("Fac %lld %lld %lld\n",N,P,PR);
	if (!N) return 1;
	LL res = 1;
	//for (LL i=2;i<=PR;i++)if (i%P)res = res*i%PR;
	res = res*mul[PR]%PR;
	//printf("%lld %lld\n",mul[PR],res);
	res = Pow(res,N/PR,PR);
	LL r = N%PR;
	//for (int i=2;i<=r;i++)if (i%P)res = res*i%PR;
	res = res*mul[r]%PR;
	//printf("%lld %lld\n",mul[r],res);
	
	return res*fac(N/P,P,PR)%PR;	
}

LL C(LL N,LL M,LL P,LL PR)
{
	mul[0] = 1;
	mul[1] = 1;
	for (LL i=2;i<=PR;i++)
	{
		mul[i] = mul[i-1];
		if (i%P)
			mul[i] = mul[i]*i%PR;
	}
	LL x = fac(N,P,PR);
	LL y = fac(M,P,PR);
	LL z = fac(N-M,P,PR);
	LL c = 0;
	for (LL i=N;i;i/=P) c+=i/P;
	for (LL i=M;i;i/=P) c-=i/P;
	for (LL i=N-M;i;i/=P) c-=i/P;
	LL a = x*inverse(y,PR)%PR*inverse(z,PR)%PR*Pow(P,c,PR)%PR;
	return a*(MOD/PR)%MOD*inverse(MOD/PR,PR)%MOD;
}

LL calc(LL N,LL M)
{
	if (N < M) return 0;
	if (N < 0 || M < 0) return 0;
	LL x = MOD,res = 0;
	//printf("Solve %lld %lld\n",N,M); 
	for (LL i=2;i<=MOD;i++)
	if (x%i==0)
	{
		LL pr = 1;
		while(x%i==0) x/=i,pr*=i;
		res = (res + C(N,M,i,pr)) % MOD;
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
		scanf("%lld%lld%lld",&N,&K,&MOD);
		ans1 = (N+K-1)/K;
		LL D = ans1 * K - N;
		ans2 = calc(D + ans1 - 1, ans1 - 1);
		printf("%lld %lld\n",ans1,ans2);
	}
}
