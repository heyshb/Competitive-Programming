#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int range = 100;
int N,Q;
int lb[100010],rb[100010],bl[100010];
LL A[100010];
LL flg[1000010];
int nxt[100010],step[100010],nxtblk[100010];
int MAGIC;
int head,tail,que[100010];

int main()
{
	freopen("HILLJUMP.in","r",stdin);
	freopen("brute.out","w",stdout);
	scanf("%d%d",&N,&Q);
	for (int i=1;i<=N;i++)scanf("%lld",&A[i]);
	while(Q--)
	{
		int type,L,R;
		LL x;
		scanf("%d%d%d",&type,&L,&R);
		//for (int i=1;i<=N;i++)printf("%lld ",A[i]);puts("");
		if (type == 1)
		{
			while(R)
			{
				int nxt = L;
				for (int i=L+1;i<=N && i<=L+range;i++)
				if (A[i] > A[L])
				{
					nxt = i;
					break;
				}
				//printf("%d %d\n",R,nxt);
				if (nxt == L) break;
				R--;
				L = nxt;
			}
			printf("%d\n",L);
			
		}
		else
		{
			scanf("%lld",&x);
			for (int i=L;i<=R;i++)A[i] += x;
		}
	}
}
