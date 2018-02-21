#include <bits/stdc++.h>

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

LL query(int L,int R)
{
	LL res = 1;
	for (int i=L;i<=R;i++)
		res = res * A[i] % d;
	return res;
}

int main()
{
	freopen("SEG.in","r",stdin);
	freopen("brute.out","w",stdout);
	int Tests;
	scanf("%d",&Tests);
	while(Tests--)
	{
		scanf("%d%d%d",&N,&d,&Q);
		for (int i=0;i<N;i++)
		{
			//T[i + M] = getint();
			scanf("%lld",&A[i]);
		}
		int up = Q / 64 + 2;
		for (int i=0;i<up;i++)
		{
			scanf("%d",&B[i]);
		}
		LL x = 0;
		int Li,Ri;
		int p = 0;
		for (int q=0;q<Q;q++)
		{
			if ((q & 63) == 0)
			{
				Li = B[p] + x;
				if (Li >= N) Li %= N;
				p++;
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
			x = query(Li,Ri) + 1;
			if (q == Q - 1)
				printf("%lld\n",x);
		}
	}
}
