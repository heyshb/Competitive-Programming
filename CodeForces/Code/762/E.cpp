#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int N,K;
struct station
{
	int x,r,f;
}S[100010];

bool cmp(station a,station b)
{
	return a.r>b.r;
}

int MAXX = 1e9;
int MAXK = 10000;
struct Node
{
	int sum,ls,rs;
}T[5000010];
int root[10010],cnt;

void ins(int x,int l,int r,int target)
{
	T[x].sum++;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (target<=mid)
	{
		if (!T[x].ls)
		{
			T[x].ls = ++cnt;
			T[cnt].ls=T[cnt].rs=T[cnt].sum=0;
		}
		ins(T[x].ls,l,mid,target);
	}
	else
	{
		if (!T[x].rs)
		{
			T[x].rs = ++cnt;
			T[cnt].ls=T[cnt].rs=T[cnt].sum=0;
		}
		ins(T[x].rs,mid+1,r,target);
	}
}

int query(int x,int l,int r,int ql,int qr)
{
	if (!x) return 0;
	if (ql>r || qr<l) return 0;
	if (ql<=l && qr>=r) return T[x].sum;
	int mid=(l+r)>>1;
	return query(T[x].ls,l,mid,ql,qr)+query(T[x].rs,mid+1,r,ql,qr);
}

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)scanf("%d%d%d",&S[i].x,&S[i].r,&S[i].f);
	sort(S+1,S+N+1,cmp);
	for (int i=1;i<=MAXK;i++)
	{
		root[i] = i;
		T[i].ls=T[i].rs=T[i].sum=0;
	}
	cnt = MAXK;
	LL ans = 0;
	for (int i=1;i<=N;i++)
	{
		int X=S[i].x,R=S[i].r,F=S[i].f;
		//printf("%d %d %d\n",X,R,F);
		for (int j=F-K;j<=F+K;j++)
		if (j>0 && j<=MAXK)
		{
			ans+=query(root[j],1,MAXX,X-R,X+R);
			//printf("QF %d %I64d\n",j,ans);
		}
		ins(root[F],1,MAXX,X);
		//printf("%I64d\n",ans);
	}
	printf("%I64d\n",ans);
}
