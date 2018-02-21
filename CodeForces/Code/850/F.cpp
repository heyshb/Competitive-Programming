#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

LL quick_pow(LL a,LL x)
{
	LL res = 1;
	while(x)
	{
		if (x & 1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return res;
}

LL rev(LL a)
{
	return quick_pow(a,MOD-2);
}

LL gcd(LL a,LL b){return b==0?a:gcd(b,a%b);}

struct frac
{
	LL x,y;
	void simp()
	{
		LL g = gcd(x,y);
		x/=g;
		y/=g;
		x%=MOD;
		y%=MOD;
		if (x<0) x+= MOD;
		if (y<0) y+= MOD;
	}
	friend frac operator * (frac a,LL v)
	{
		frac b;
		a.simp();
		b.simp();
		b.x = a.x*v;
		b.y = a.y;
		b.simp();
		return b; 
	}
	friend frac operator + (frac a,frac b)
	{
		frac c;
		a.simp();
		b.simp();
		c.x = a.x*b.y+a.y*b.x;
		c.y = a.y*b.y;
		c.simp();
		return c;
	}
	friend frac operator - (frac a,frac b)
	{
		frac c;
		a.simp();
		b.simp();
		c.x = a.x*b.y-a.y*b.x;
		c.y = a.y*b.y;
		c.simp();
		return c;
	}
}ans[100010];

int N;
int a[100010];
LL S = 0;

int main()
{
	scanf("%d",&N);
	int mx = 0;
	for (int i=1;i<=N;i++)scanf("%d",&a[i]),S+=LL(a[i]),mx=max(mx,int(a[i]));
	ans[0].x = 0;
	ans[0].y = 1;
	ans[1].x = (S-1)*(S-1);
	ans[1].y = S;
	ans[1].simp();
	//printf("%lld %lld\n",ans[1].x,ans[1].y);
	for (int i=2;i<=mx;i++)
	{
		ans[i] = ans[i-1] * 2LL;
		//printf("!!%lld %lld\n",ans[i].x,ans[i].y);
		ans[i] = ans[i] - ans[i-2];
		//printf("!!%lld %lld\n",ans[i].x,ans[i].y);
		ans[i] = ans[i] - (frac){S-1,S-i+1};
		//printf("%lld %lld\n",ans[i].x,ans[i].y);
	}
	frac last = (frac){0,1};
	for (int i=1;i<=N;i++) last = last + ans[a[i]];
	//printf("%lld %lld\n",last.x,last.y);
	printf("%lld\n",last.x*rev(last.y)%MOD);
}
