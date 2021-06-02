#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 1000000007;

int N,M;
LL tr[100010];
LL d[100010];//a[i] - a[i-1]
int lowbit(int x){return x&-x;}
int offset = 5;
LL getsum(int x){x+=offset;LL s=0;while(x){s+=tr[x];x-=lowbit(x);}return s;}
void add(int x,LL y){x+=offset;while(x<=M+offset){tr[x]+=y;x+=lowbit(x);}}
struct event
{
	int type,l,r;
	LL cnt;
}e[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for (int i=1;i<=M;i++)scanf("%d%d%d",&e[i].type,&e[i].l,&e[i].r),e[i].cnt = 1;
		memset(tr,0,sizeof(tr));
		memset(d,0,sizeof(d));
		for (int i=M;i>=1;i--)
		if (e[i].type == 1)
		{
			e[i].cnt += getsum(i);
			e[i].cnt %= MOD;
			d[e[i].r+1] -= e[i].cnt; 
			d[e[i].l] += e[i].cnt;
		}
		else
		{
			e[i].cnt += getsum(i);
			e[i].cnt %= MOD;
 			add(e[i].l,e[i].cnt);
			add(e[i].r+1,-e[i].cnt);
		}
		LL s = 0;
		for (int i=1;i<=N;i++)
		{
			s = ((s + d[i]) % MOD + MOD ) % MOD;
			printf("%lld%c",s," \n"[i==N]);
		}
	}
}
