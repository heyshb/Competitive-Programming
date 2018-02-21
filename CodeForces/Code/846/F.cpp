#include <bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 1000010;
int N,A[1000010],last[1000010],nxt[1000010];
LL T[4*MAXN];
int tag[4*MAXN];

void pushdown(int x,int l,int r)
{
	if (tag[x])
	{
		T[x*2] += 1LL * tag[x] * (mid+1-l);
		T[x*2+1] += 1LL * tag[x] * (r-mid);
		tag[x*2] += tag[x];
		tag[x*2+1] += tag[x];
		tag[x] = 0;
	}
}

void add(int x,int l,int r,int ql,int qr,int d)
{
	if (ql <= l && qr >= r)
	{
		tag[x] += d;
		T[x] += 1LL * d * (r - l + 1);
		return;
	}
	pushdown(x,l,r);
	if (ql <= mid) add(x*2,l,mid,ql,qr,d);
	if (qr > mid) add(x*2+1,mid+1,r,ql,qr,d);
	T[x] = T[x*2] + T[x*2+1];
}

LL getsum(int x,int l,int r,int ql,int qr)
{
	LL res = 0;
	if (ql <= l && qr >= r) return T[x];
	pushdown(x,l,r);
	if (ql <= mid) res += getsum(x*2,l,mid,ql,qr);
	if (qr > mid) res += getsum(x*2+1,mid+1,r,ql,qr);
	return res;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=N;i++)last[A[i]] = N+1;
	for (int i=N;i>=1;i--)
	{
		nxt[i] = last[A[i]];
		last[A[i]] = i;
	}
	LL S = 0;
	memset(T,0,sizeof(T));
	memset(tag,0,sizeof(tag));
	int ss = 0; 
	for (int i=1;i<=N;i++)
	{
		if (last[A[i]] == i) ss++;
		//printf("add %d %d %d\n",i,i,ss);
		add(1,1,N,i,i,ss);
	}
	for (int i=1;i<=N;i++)
	{
		//printf("get %d-%d\n",i+1,N);
		S += getsum(1,1,N,i+1,N);
		//printf("del %d-%d\n",i,nxt[i]-1);
		add(1,1,N,i,nxt[i]-1,-1);
		//printf("%lld\n",S);
	}
	S *= 2LL;
	S += N;
	printf("%.10lf\n",1.0*S/(1.0*N*N));
}
