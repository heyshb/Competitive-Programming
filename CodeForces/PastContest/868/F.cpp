#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K,A[100010];
LL f[21][100010]; 
int cnt[100010];

void solve(int k,int L,int R,int xL,int xR)
{
	if (L > R) return;
	printf("solve %d %d %d %d %d\n",k,L,R,xL,xR);
	int mid = (L + R) >> 1;
	int best;
	int myR = min(mid-1,xR);
	LL v = 0;
	for (int i=mid;i>myR;i--)
	{
		v += cnt[A[i]];
		cnt[A[i]]++;
	}
	printf("%d %d\n",xL,myR);
	for (int i=myR;i>=xL;i--)
	{
		//printf("%d %lld %lld\n",i,f[k-1][i] + v,f[k][mid]);
		if (f[k-1][i] + v < f[k][mid])
		{
			f[k][mid] = f[k-1][i] + v;
			//printf("f %d %d = %lld\n",k,mid,f[k][mid]);
			best = i;
		}
		printf("f %d %d = %lld\n",k,mid,f[k][mid]);
		v += cnt[A[i]];
		cnt[A[i]]++;
	}
	for (int i=xL;i<=myR;i++)cnt[A[i]]--;
	solve(k,L,mid-1,xL,best);
	solve(k,mid+1,R,best,xR);
}

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=K;i++)
		for (int j=1;j<=N;j++)
			f[i][j] = 1e15;
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=N;i++)
	{
		f[1][i] = f[1][i-1] + cnt[A[i]];
		cnt[A[i]]++;
	}
	memset(cnt,0,sizeof(cnt));
	for (int k=2;k<=K;k++)
		solve(k,1,N,1,N);
	printf("%lld\n",f[K][N]);
}
