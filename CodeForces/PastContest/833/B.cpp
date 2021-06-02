#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int a[35010];
int N,K;
int f[51][35010];
int lst[35010];
int vis[35010];
int T[400010];
int flg[400010];
int g[51][35010];
void pushdown(int x)
{
	if (flg[x] != 0)
	{
		T[x*2] += flg[x];
		T[x*2+1] += flg[x];
		flg[x*2] += flg[x];
		flg[x*2+1] += flg[x];
		flg[x] = 0;
	}
}

void modify(int x,int l,int r,int v,int ql,int qr)
{
	pushdown(x);
	if (ql <= l && qr >= r)
	{
		flg[x] += v;
		T[x] += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid)
		modify(x*2,l,mid,v,ql,qr);
	if (qr > mid)
		modify(x*2+1,mid+1,r,v,ql,qr);
	T[x] = max(T[x*2],T[x*2+1]);
}

int getmax(int x,int l,int r,int ql,int qr)
{
	
	pushdown(x);
	if (ql <= l && qr >= r) return T[x];
	int mid = (l + r) >> 1;
	int res = -1000000000;
	if (ql <= mid)
		res = max(res,getmax(x*2,l,mid,ql,qr));
	if (qr > mid)
		res = max(res,getmax(x*2+1,mid+1,r,ql,qr));
	return res;
}

int dif(int l,int r)
{
	int cnt = 0;
	for (int i=l;i<=r;i++)
	if (lst[i] < l) cnt++;
	return cnt;
}

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	//N = 100;
	//K = 10;
	//for (int i=1;i<=N;i++)a[i] = rand() % 10 + 1;
	//for (int i=1;i<=N;i++)printf("%d ",a[i]);puts("");
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=N;i++)
	{
		lst[i] = vis[a[i]];
		vis[a[i]] = i;
	}
	//for (int i=1;i<=N;i++)printf("%d\n",lst[i]);
	f[1][0] = 0;
	for (int i=1;i<=N;i++)
	{
		f[1][i] = f[1][i-1];
		if (!lst[i]) 
			f[1][i]++;
	}
	for (int i=2;i<=K;i++)
	{
		for (int j=1;j<=4*N;j++)T[j] = flg[j] = 0;
		for (int j=1;j<=N;j++)modify(1,0,N,f[i-1][j],j,j);
		for (int j=i;j<=N;j++)
		{
			modify(1,0,N,1,lst[j],j-1);
			f[i][j] = getmax(1,0,N,i-1,j-1);
		}
	}
	/*
	for (int i=1;i<=K;i++)
	{
		for (int j=1;j<=N;j++)printf("%d ",f[i][j]);
		puts("");
	}*/
	printf("%d\n",f[K][N]);
}
