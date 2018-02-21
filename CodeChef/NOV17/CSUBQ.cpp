#include <bits/stdc++.h>
#define ls (x << 1)
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)
#define mp make_pair
using namespace std;

int N,Q,L,R;
typedef long long LL;
struct Node
{
	int l1,r1;
	LL ans;
};
typedef pair<LL,pair<LL,LL> > pp;
const int MAXN = 500010;
struct SegmentTree
{
	Node T[MAXN << 2];
	
	void maintain(int x,int l,int r)
	{
		if (T[ls].l1 == mid + 1 - l)
			T[x].l1 = T[ls].l1 + T[rs].l1;
		else
			T[x].l1 = T[ls].l1;
		
		if (T[rs].r1 == r - mid)
			T[x].r1 = T[rs].r1 + T[ls].r1;
		else
			T[x].r1 = T[rs].r1;
			
		T[x].ans = T[ls].ans + T[rs].ans + 1LL*T[ls].r1*T[rs].l1;
	}
	
	void modify(int x,int l,int r,int pos,int v)
	{
		if (l == r)
		{
			T[x].l1 = T[x].r1 = T[x].ans = v;
			return;
		}
		if (pos <= mid)
			modify(ls,l,mid,pos,v);
		else
			modify(rs,mid+1,r,pos,v);
		maintain(x,l,r);
	}
	
	pp uno(pp p1,pp p2,int len1,int len2)
	{
		LL a,b,c;
		b = p1.second.first;
		if (p1.second.first == len1) b += p2.second.first;
		c = p2.second.second;
		if (p2.second.second == len2) c += p1.second.second;
		a = p1.first + p2.first + p1.second.second * p2.second.first;
		return mp(a,mp(b,c));
	}
	
	pp query(int x,int l,int r,int ql,int qr)
	{
		if (l == ql && r == qr)
			return mp(T[x].ans,mp(T[x].l1,T[x].r1));
		
		if (qr <= mid)
			return query(ls,l,mid,ql,qr);
		else if (ql > mid)
			return query(rs,mid+1,r,ql,qr);
		else
			return uno(query(ls,l,mid,ql,mid),query(rs,mid+1,r,mid+1,qr),mid+1-l,r-mid);
	}
}T1,T2;

int main()
{
	scanf("%d%d%d%d",&N,&Q,&L,&R);
	for (int i=1;i<=N;i++)
	{
		T1.modify(1,1,N,i,1);
		T2.modify(1,1,N,i,1);
	}
	while(Q--)
	{
		int type,x,y;
		scanf("%d%d%d",&type,&x,&y);
		if (type == 1)
		{
			T1.modify(1,1,N,x,(y < L));
			T2.modify(1,1,N,x,(y <= R));
		}
		else
		{
			pp ans1,ans2;
			ans1 = T1.query(1,1,N,x,y);
			ans2 = T2.query(1,1,N,x,y);
			printf("%lld\n",ans2.first - ans1.first);
		}
	}
}
