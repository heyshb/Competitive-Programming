#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
int tr[500010];
int lowbit(int x){return x&-x;}
int getsum(int x){int res = 0;while(x){res+=tr[x];x-=lowbit(x);}return res;}
void add(int x,int y){while(x<=N){tr[x]+=y;x+=lowbit(x);}}

int dist(int l1,int r1,int l2,int r2)
{
	if (l1>l2)
	{
		swap(l1,l2);
		swap(r1,r2);
	}
	if (l2<=r1) return 0;
	return l2-r1;
}

struct seg
{
	int l,r;
}A[200010],B[200010];


int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d%d",&A[i].l,&A[i].r);
	scanf("%d",&M);
	for (int i=1;i<=M;i++)scanf("%d%d",&B[i].l,&B[i].r);
	int MM = 2147483600,minpos;
	int ans = 0;
	for (int i=1;i<=N;i++)
	if (A[i].r<MM)
	{
		MM = A[i].r;
		minpos = i;
	}
	for (int i=1;i<=M;i++)
	ans = max(ans,dist(A[minpos].l,A[minpos].r,B[i].l,B[i].r));
	
	MM = -2147483600,minpos;
	for (int i=1;i<=N;i++)
	if (A[i].l>MM)
	{
		MM = A[i].l;
		minpos = i;
	}
	for (int i=1;i<=M;i++)
	ans = max(ans,dist(A[minpos].l,A[minpos].r,B[i].l,B[i].r));
	printf("%d\n",ans);
}
