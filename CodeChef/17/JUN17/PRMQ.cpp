#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,Q;
#define B 1000000
LL A[100010];
bool ok[B + 10];
struct query
{
	int X,P,num,ans;
}q[400010];
bool cmp1(query a,query b){return a.X < b.X;}
bool cmp2(query a,query b){return a.num < b.num;}
vector<int>prime;
int cnt = 0;
int tr[B+10];
int lowbit(int x){return x&-x;}
void add(int x,int y){while(x<=B){tr[x]+=y;x+=lowbit(x);}}
int getsum(int x){int s=0;while(x){s+=tr[x];x-=lowbit(x);}return s;}
void ins(int x)
{
	for (int i=0;i<cnt;i++)
	if (x%prime[i]==0)
	{
		int tmp = 0;
		while(x%prime[i]==0)
		{
			x/=prime[i];
			tmp++;
		}
		add(prime[i],tmp);
		if (x==1) return;
	}
	add(x,1);
}
void solve()
{
	int now = 0;
	for (int i=1;i<=4*Q;i++)
	{
		//printf("%d %d\n",q[i].X,q[i].P);
		while(now<q[i].X)ins(A[++now]);
		q[i].ans = getsum(q[i].P);
	}
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lld",&A[i]);
	memset(ok,true,sizeof(ok));
	for (int i=2;i<=B;i++)
	{
		if (ok[i]) 
		{
			prime.push_back(i);
			if (i<=1000)
				cnt++;
		}
		for (int j=0;j<prime.size() && i*prime[j]<=B;j++)
		{
			ok[i*prime[j]] = false;
			if (i%prime[j] == 0) break;
		}
	}
	scanf("%d",&Q);
	for (int i=0;i<Q;i++)
	{
		int L,R,X,Y;
		scanf("%d%d%d%d",&L,&R,&X,&Y);
		q[i*4+1] = (query){R,Y,i*4+1,0};
		q[i*4+2] = (query){R,X-1,i*4+2,0};
		q[i*4+3] = (query){L-1,Y,i*4+3,0};
		q[i*4+4] = (query){L-1,X-1,i*4+4,0};
	}
	sort(q+1,q+4*Q+1,cmp1);
	solve();
	sort(q+1,q+4*Q+1,cmp2);
	for (int i=0;i<Q;i++)
	{
		printf("%d\n",q[i*4+1].ans-q[i*4+2].ans-q[i*4+3].ans+q[i*4+4].ans);
	}
}
