#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long LL;

int N,M;
int A[100010];

int tr[500010];
int lowbit(int x){return x&-x;}
int getsum(int x){int res = 0;while(x){res+=tr[x];x-=lowbit(x);}return res;}
void add(int x,int y){while(x<=N){tr[x]+=y;x+=lowbit(x);}}

LL quick_pow(LL a,LL x) 
{
	LL res = 1;
	while(x)
	{
		if (x&1) res=res*a%MOD;
		a=a*a%MOD;
		x>>=1;
	}
	return res;
}

LL fac[400010],rev[400010];
char s[200010];

LL C(LL N,LL M)
{
	if (N<M) return 0;
	return ((fac[N]*rev[M])%MOD)*rev[N-M]%MOD;
}

LL calc(LL N,LL M)
{
	//printf("%I64d %I64d\n",N,M);
	LL res = C(N+M-1,M-1);
	//printf("%I64d\n",res);
	return res;
}

int main()
{
	fac[0] = 1;
	for (int i=1;i<=400000;i++)fac[i] = fac[i-1]*LL(i)%MOD;
	rev[400000] = quick_pow(fac[400000],MOD-2);
	for (int i=399999;i>=1;i--)rev[i] = rev[i+1]*LL(i+1)%MOD;
	rev[0] = 1;
	scanf("%s",s);
	LL S1 = 0, S2 = 0;
	int len = strlen(s);
	for (int i=0;i<len;i++)S2+=(s[i]==')');
	LL ans = 0;
	for (int i=0;i<len;i++)
	{
		if (s[i]=='(')
		{
			S1++;
			ans+=calc(S1,S2);
			ans%=MOD;
		}
		else
			S2--;
	}
	printf("%I64d\n",ans);
}
