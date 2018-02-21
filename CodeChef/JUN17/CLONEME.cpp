#include <bits/stdc++.h>

using namespace std;

int N,Q;
int A[100010],root[100010];
typedef long long LL;
const LL seed = 233;
const LL MOD = 1000000007;
LL p[100010],r[100010];
const int BB = 100000;

LL quick_pow(LL a,LL x)
{
	LL res = 1;
	while(x)
	{
		if (x&1) res = res * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return res;
}

int cnt;
struct Node
{
	int ls,rs,sum;
	LL H;
}T[4000010];

LL Gethash(int x,int l,int r,int ql,int qr)
{
	if (!x) return 0;
	if (ql > qr) return 0;
	if (l == ql && r == qr) return T[x].H;
	int mid = (l+r)>>1;
	if (qr <= mid) return Gethash(T[x].ls,l,mid,ql,qr);
	if (ql > mid) return Gethash(T[x].rs,mid+1,r,ql,qr);
	LL hl = Gethash(T[x].ls,l,mid,ql,mid);
	LL hr = Gethash(T[x].rs,mid+1,r,mid+1,r);
	return (hl*p[qr-mid]%MOD + hr) % MOD; 
}

int Getsum(int x,int l,int r,int ql,int qr)
{
	//printf("%d %d %d %d %d: %d\n",x,l,r,ql,qr,T[x].sum);
	if (!x) return 0;
	if (ql > qr) return 0;
	if (l==ql && r==qr) return T[x].sum;
	int mid = (l+r)>>1;
	if (qr <= mid) return Getsum(T[x].ls,l,mid,ql,qr);
	if (ql > mid) return Getsum(T[x].rs,mid+1,r,ql,qr);
	return Getsum(T[x].ls,l,mid,ql,mid) + Getsum(T[x].rs,mid+1,r,mid+1,qr);
}

int ins(int x,int l,int r,int v)
{
	int now = ++cnt;
	T[now].sum = T[x].sum + 1;
	if (l == r)
	{
		T[now].H = T[now].sum;
		T[now].ls = T[now].rs = 0;
	}
	else
	{
		int mid = (l+r) >> 1;	
		if (v <= mid)
		{
			T[now].rs = T[x].rs;
			T[now].ls = ins(T[x].ls,l,mid,v);
		}
		else
		{
			T[now].ls = T[x].ls;
			T[now].rs = ins(T[x].rs,mid+1,r,v);
		}
		LL hl = T[T[now].ls].H;
		LL hr = T[T[now].rs].H;
		T[now].H = (hl*p[r-mid]%MOD + hr) % MOD; 
	}	
	return now;
}

LL same(LL A,LL B,LL C,LL D)
{
	return (B-A+MOD)%MOD == (D-C+MOD)%MOD;
}

void down(int &x,int ch)
{
	if (ch == 0)
		x = T[x].ls;
	else
		x = T[x].rs;
}

bool similar(int A,int B,int C,int D)
{
	A--;
	C--;
	if (same(T[root[A]].H,T[root[B]].H,T[root[C]].H,T[root[D]].H)) return true;
	//if ((root[B].H + root[D].H - root[A].H - root[C].H + 2LL*MOD) % MOD == 0) return true;
	int fd,ld;
	int na,nb,nc,nd;
	int l,r,mid;
	
	na = root[A];
	nb = root[B];
	nc = root[C];
	nd = root[D];
	l = 1;
	r = BB;
	while(l!=r)
	{
		mid = (l+r)>>1;
		if (same(T[T[na].ls].H,T[T[nb].ls].H,T[T[nc].ls].H,T[T[nd].ls].H))
		{
			down(na,1);down(nb,1);down(nc,1);down(nd,1);
			l = mid+1;
		}
		else
		{
			down(na,0);down(nb,0);down(nc,0);down(nd,0);
			r = mid;
		}
	}
	fd = l;
	
	na = root[A];
	nb = root[B];
	nc = root[C];
	nd = root[D];
	l = 1;
	r = BB;
	while(l!=r)
	{
		mid = (l+r)>>1;if (same(T[T[na].rs].H,T[T[nb].rs].H,T[T[nc].rs].H,T[T[nd].rs].H))
		{
			down(na,0);down(nb,0);down(nc,0);down(nd,0);
			r = mid;
		}
		else
		{
			down(na,1);down(nb,1);down(nc,1);down(nd,1);
			l = mid+1;
		}
	}
	ld = l;
	
	assert(ld > fd);
	if (Getsum(root[B],1,BB,fd+1,ld-1) != Getsum(root[A],1,BB,fd+1,ld-1)) return false;
	if (Getsum(root[D],1,BB,fd+1,ld-1) != Getsum(root[C],1,BB,fd+1,ld-1)) return false;
	int s1 = Getsum(root[B],1,BB,fd,fd) - Getsum(root[A],1,BB,fd,fd);
	int s2 = Getsum(root[D],1,BB,fd,fd) - Getsum(root[C],1,BB,fd,fd);
	return (s1 == s2+1 || s1 == s2-1);
}

int main()
{
	//freopen("CLONEME.in","r",stdin);
	p[0] = 1;
	for (int i=1;i<=100000;i++) p[i] = p[i-1] * seed % MOD;
	r[0] = 1;
	LL rr = quick_pow(seed,MOD-2);
	for (int i=1;i<=100000;i++) r[i] = r[i-1] * rr % MOD;
	int TT;
	scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d%d",&N,&Q);
		root[0] = cnt = 1;
		T[1].ls = T[1].rs = T[1].sum = 0;
		T[1].H = 0;
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&A[i]);
			root[i] = ins(root[i-1],1,BB,A[i]);
			//printf("%d %lld\n",root[i],T[root[i]].H);
		}
		while(Q--)
		{
			int A,B,C,D;
			scanf("%d%d%d%d",&A,&B,&C,&D);
			puts(similar(A,B,C,D)?"YES":"NO");
		}
	}
}
