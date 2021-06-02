#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef unsigned long long LL; 
LL T[2501*2501*4],T2[2501*2501*4];
map<pair<pair<int,int>,pair<int,int> >,LL> num;
int N,M,Q;

LL getrand()
{
	return ((LL)rand()<<31) + rand();
}

void modify(int x,int u,int d,int l,int r,int du,int dd,int dl,int dr,LL hsh,int V)
{
	if (u > d || l > r) return;
	if (du > d || dd < u || dl > r || dr < l) return;
	//printf("jinru %d %d %d %d\n",u,d,l,r);
	//if (u <= du && d <= dd && l >= dl && r <= dr)
	if (du <= u && dd >= d && dl <= l && dr >= r)
	{
		//printf("wow %d %d %d %d %llu %d %d %d %d\n",u,d,l,r,hsh,du,dd,dl,dr);
		if (V == 1)
		{
			T[x] += hsh;
			T2[x] ^= hsh;
		}
		else
		{
			T[x] -= hsh;
			T2[x] ^= hsh;
		}
		return;
	}
	int mid1 = (u + d) / 2, mid2 = (l + r) / 2;
	modify(x*4-2,u,mid1,l,mid2,du,dd,dl,dr,hsh,V);
	modify(x*4-1,u,mid1,mid2+1,r,du,dd,dl,dr,hsh,V);
	modify(x*4,mid1+1,d,l,mid2,du,dd,dl,dr,hsh,V);
	modify(x*4+1,mid1+1,d,mid2+1,r,du,dd,dl,dr,hsh,V);
}
const int INF = 10000000;

void gao(pair<LL,LL> &p1,pair<LL,LL> p2)
{
	p1.first += p2.first;
	p1.second ^= p2.second;
}

pair<LL,LL> query(int x,int u,int d,int l,int r,int qx,int qy)
{
	if (u==d && l==r) return mp(T[x],T2[x]);
	int mid1 = (u + d) / 2, mid2 = (l + r) / 2;
	pair<LL,LL> ret = mp(T[x],T2[x]);
	if (qx <= mid1)
	{
		if (qy <= mid2)
		{
			gao(ret,query(x*4-2,u,mid1,l,mid2,qx,qy));
		}
		else
		{
			gao(ret,query(x*4-1,u,mid1,mid2+1,r,qx,qy));
		}
	}
	else
	{
		if (qy <= mid2)
		{
			gao(ret,query(x*4,mid1+1,d,l,mid2,qx,qy));
		}
		else
		{
			gao(ret,query(x*4+1,mid1+1,d,mid2+1,r,qx,qy));
		}
	}
	return ret;
}

int main()
{
	srand(252);
	scanf("%d%d%d",&N,&M,&Q);
	for (int Case=1;Case<=Q;Case++)
	{
		//puts("0000");
		//printf("%llu\n",num[mp(mp(2,2),mp(4,5))]);
		int type,u,l,d,r;
		scanf("%d%d%d%d%d",&type,&u,&l,&d,&r);
		if (type == 1)
		{
			num[mp(mp(u,l),mp(d,r))] = getrand();
			modify(1,1,N,1,M,u,d,l,r,num[mp(mp(u,l),mp(d,r))],1);
		}
		if (type == 2)
		{
			modify(1,1,N,1,M,u,d,l,r,num[mp(mp(u,l),mp(d,r))],-1);
		}
		if (type == 3)
		{
			pair<LL,LL> num1 = query(1,1,N,1,M,u,l), num2 = query(1,1,N,1,M,d,r);
			//printf("%llu %llu\n",num1.first,num1.second);
			//printf("%llu %llu\n",num2.first,num2.second);
			puts(num1.first==num2.first && num1.second==num2.second?"Yes":"No");
		}
	}
}
