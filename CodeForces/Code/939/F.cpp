#include <bits/stdc++.h>

using namespace std;

int N,K;
int f[110][200010];
int L[110],R[110];
int a[200010];
int T[1000010];

int getmin(int x,int L,int R,int ql,int qr)
{
	if (L == ql && R == qr) return T[x];
	int mid = (L + R) / 2;
	if (ql > mid)
		return getmin(x*2+1,mid+1,R,ql,qr);
	if (qr <= mid)
		return getmin(x*2,L,mid,ql,qr);
	return min(getmin(x*2,L,mid,ql,mid), getmin(x*2+1,mid+1,R,mid+1,qr));
}

void build(int x,int L,int R)
{
	if (L == R)
	{
		T[x] = a[L];
		return;
	}
	int mid = (L + R) / 2;
	build(x*2,L,mid);
	build(x*2+1,mid+1,R);
	T[x] = min(T[x*2],T[x*2+1]);
}

//[0,2N]
const int INF = 1000000000;
int main()
{
	//freopen("F.in","r",stdin);
	scanf("%d%d",&N,&K);
	for (int i=1;i<=K;i++)scanf("%d%d",&L[i],&R[i]);
	for (int i=0;i<=2*N;i++)a[i] = INF;
	a[N] = 0;
	for (int i=0;i<=K;i++)
		for (int j=0;j<=2*N;j++)f[i][j] = INF;
	f[0][N] = 0;
	build(1,0,2*N);
	for (int i=1;i<=K;i++)
	{
		//printf("FLIP %d\n",i);
		for (int j=R[i]-R[i-1];j<=2*N;j++)
		{
			f[i][j] = f[i-1][j-(R[i]-R[i-1])];
		}
		for (int j=0;j<=2*N;j++)
		{
			int ql,qr;
			ql = 2*N - j - (R[i]-R[i-1]);
			qr = 2*N - j - (L[i]-R[i-1]) + (R[i]-L[i]);
			
			ql = max(0,ql);
			ql = min(2*N,ql);
			qr = max(0,qr);
			qr = min(2*N,qr);
			f[i][j] = min(f[i][j],getmin(1,0,2*N,ql,qr) + 1);
			
			ql = j - (L[i] - R[i-1]) - (R[i] - L[i]);
			qr = j - (L[i] - R[i-1]) + (R[i] - L[i]);
			
			ql = max(0,ql);
			ql = min(2*N,ql);
			qr = max(0,qr);
			qr = min(2*N,qr);
			f[i][j] = min(f[i][j],getmin(1,0,2*N,ql,qr) + 2);
		}
		for (int j=0;j<=2*N;j++)a[j] = f[i][j];
		build(1,0,2*N);
	}
	if (N-(2*N-R[K]) >= 0 && f[K][N-(2*N-R[K])] < INF / 2)
	{
		puts("Full");
		printf("%d\n",f[K][N-(2*N-R[K])]);
	}
	else
	{
		puts("Hungry");
	}
}
