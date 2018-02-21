#include <bits/stdc++.h>
#define po2(x) (II(1) << (x))
using namespace std;

typedef long long LL;
typedef __int128 II;

int N,M,Q,d;
int A[5000010];
LL T[9000010];
int B[5000010];
int p;
LL Magic;
const int W = 64;

inline int readaaaa()
{
    int X=0,w=0; char ch=0;
    while(ch<'0' || ch>'9') {w|=ch=='-';ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int _read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}

/*
inline II po2(int p)
{
	return II(1) << p;
}*/

void getMagic()
{
	II x = po2(W-1) - po2(W-1)%d - 1, t;
	for(p=0;t=po2(p),t<=x*(d-t%d);p++);
	if (p < W) p = W, t = po2(W);
	Magic = (t + d - t % d) / d;
}

LL MOD(LL x)
{
	LL t = II(x) * Magic >> W;
	if (Magic < 0) t += x;
	return x - (t >> (p - W)) * d;
}


LL query(int Li,int Ri)
{
	Li--;
	Ri++;
	Li += M;
	Ri += M;
	LL ans = 1;
	while((Li ^ Ri) != 1)
	{
		//printf("gtm %d %d\n",Li,Ri);
		if (~Li & 1) 
		{
			//printf("fuck %d\n",Li+1);
			ans = MOD(ans*T[Li+1]);
		}
		if (Ri & 1) 
		{
			//printf("fuck %d\n",Ri-1);
			ans = MOD(ans*T[Ri-1]); 
		}
		Li >>= 1;
		Ri >>= 1;
	}
	return ans;
}

int main()
{
	//freopen("SEG.in","r",stdin);
	//freopen("SEG.out","w",stdout);
	int Tests;
	//scanf("%d",&Tests);
	Tests = _read();
	//printf("Tests = %d\n",Tests);
	while(Tests--)
	{
		//scanf("%d%d%d",&N,&d,&Q);
		N = _read();
		d = _read();
		Q = _read();
		getMagic(); 
		M = 1;
		while(M <= (N + 2))
			M <<= 1;
		for (int i=M;i<=2*M;i++)T[i] = 1;
		for (int i=1;i<=N;i++)
		{
			//T[i + M] = getint();
			//scanf("%lld",&T[i + M]);
			T[i + M] = _read();
		}
		for (int i=M-1;i>=1;i--)
		{
			T[i] = MOD(T[i << 1] * T[(i << 1) | 1]);
		}
		int up = Q / 64 + 2;
		for (int i=0;i<up;i++)
		{
			//scanf("%d",&B[i]);
			B[i] = _read();
		}
		LL x = 0;
		int Li,Ri;
		int p = 0;
		for (int q=0;q^Q;++q)
		{
			if (!(q & 63))
			{
				Li = B[p] + x;
				if (Li >= N) Li %= N;
				++p;
				Ri = B[p] + x;
				if (Ri >= N) Ri %= N;
			}
			else
			{
				Li += x;
				if (Li >= N) Li %= N;
				Ri += x;
				if (Ri >= N) Ri %= N;
			}
			if (Li > Ri) swap(Li, Ri);
			//printf("Query %d %d\n",Li,Ri);
			x = query(Li + 1,Ri + 1) + 1;
			if (x >= d)
				x = MOD(x); 
		}
		printf("%lld\n",x);
	}
}
