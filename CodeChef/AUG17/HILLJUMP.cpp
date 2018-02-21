#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int range = 100;
int N,Q;
int lb[100010],rb[200010],bl[200010];
LL A[200010];
LL flg[200010];
int nxt[200010],step[200010],nxtblk[200010];
int MAGIC;
int head,tail,que[200010];

void update(int x,int y)
{
	nxt[x] = y;
	if (x == y)
	{
		step[x] = N + 1;
		nxtblk[x] = x;
	}
	else if (bl[x] == bl[y])
	{
		step[x] = step[y] + 1;
		nxtblk[x] = nxtblk[y];
	}
	else
	{
		nxtblk[x] = y;
		step[x] = 1;
	}
}

void pushdown(int x)
{
	if (flg[x])
	{
		for (int i=lb[x];i<=rb[x];i++)A[i] += flg[x];
		flg[x] = 0; 
	}
}

int query(int x,int st)
{
	while(st)
	{
		if (x == nxt[x]) return x;
		if (step[x] <= st)
		{
			st -= step[x];
			x = nxtblk[x];
		}
		else
		{
			st--;
			x = nxt[x];
		}
	}
	return x;
}

int main()
{
	freopen("HILLJUMP.in","r",stdin);
	freopen("hill.out","w",stdout);freopen("hill.out","w",stdout);
	scanf("%d%d",&N,&Q);
	for (int i=1;i<=N;i++)scanf("%lld",&A[i]);
	MAGIC = int(sqrt(N) + 1);
	for (int i=1;i<=N;i++)
	{
		bl[i] = (i - 1) / MAGIC + 1;
		if (!lb[bl[i]]) lb[bl[i]] = i;
		rb[bl[i]] = i;
	}
	head = 1;
	tail = 0;
	for (int i=N;i>=1;i--)
	{
		//printf("%d\n",i);
		while(head <= tail && que[head] > i + range) head++;
		//for (int j=head;j<=tail;j++)printf("%d ",que[j]);puts("");
		//printf("%d-%d %d %d %d\n",head,tail,A[que[head]],A[que[tail]],A[i]);
		if (head > tail || A[que[head]] <= A[i]) update(i,i);
		else if (A[que[tail]] > A[i]) update(i,que[tail]);
		else
		{
			//printf("%d %d %d\n",head<=tail,A[que[head]] > A[i],A[que[tail]] <= A[i]);
			assert(head <= tail && A[que[head]] > A[i] && A[que[tail]] <= A[i]);
			int l,r;
			l = head, r = tail;
			while(l != r-1)
			{
				int mid = (l + r) >> 1;
				if (A[que[mid]] > A[i])
					l = mid;
				else
					r = mid;
			}
			update(i,que[l]);
		}
		while(head <= tail && A[que[tail]] <= A[i]) tail--;
		que[++tail] = i; 
		//for (int j=head;j<=tail;j++)printf("%d ",que[j]);puts("");
	}
	//for (int i=1;i<=N;i++)printf("%d: bl=%d nxt=%d step=%d nxtblk=%d\n",i,bl[i],nxt[i],step[i],nxtblk[i]);
	while(Q--)
	{
		//puts("");
		int type,L,R;
		LL x;
		scanf("%d%d%d",&type,&L,&R);
		if (type == 1)
		{
			printf("%d\n",query(L,R));
		}
		else
		{
			scanf("%lld",&x);
			for (int i=bl[L]+1;i<bl[R];i++)flg[i] += x;
			if (bl[L] == bl[R])
			{
				for (int i=L;i<=R;i++)A[i] += x;
			}
			else
			{
				for (int i=L;i<=rb[bl[L]];i++) A[i] += x;
				for (int i=lb[bl[R]];i<=R;i++) A[i] += x;
			}
			head = 1;
			tail = 0;
			for (int i=min(L+range,N);i>=lb[bl[L-range]] && i;i--)
			{
				pushdown(bl[i]);
				while(head <= tail && que[head] > i + range) head++;
				if (i <= L)
				{
					if (head > tail || A[que[head]] <= A[i]) update(i,i);
					else if (A[que[tail]] > A[i]) update(i,que[tail]);
					else
					{
						assert(head <= tail && A[que[head]] > A[i] && A[que[tail]] <= A[i]);
						int l,r;
						l = head, r = tail;
						while(l != r-1)
						{
							int mid = (l + r) >> 1;
							if (A[que[mid]] > A[i])
								l = mid;
							else
								r = mid;
						}
						update(i,que[l]);
					}
				}
				while(head <= tail && A[que[tail]] <= A[i]) tail--;
				que[++tail] = i; 
			}
			
			head = 1;
			tail = 0;
			for (int i=min(R+range,N);i>=lb[bl[R-range]] && i;i--)
			{
				pushdown(bl[i]);
				while(head <= tail && que[head] > i + range) head++;
				if (i <= R)
				{
					if (head > tail || A[que[head]] <= A[i]) update(i,i);
					else if (A[que[tail]] > A[i]) update(i,que[tail]);
					else
					{
						assert(head <= tail && A[que[head]] > A[i] && A[que[tail]] <= A[i]);
						int l,r;
						l = head, r = tail;
						while(l != r-1)
						{
							int mid = (l + r) >> 1;
							if (A[que[mid]] > A[i])
								l = mid;
							else
								r = mid;
						}
						update(i,que[l]);
					}
				}
				while(head <= tail && A[que[tail]] <= A[i]) tail--;
				que[++tail] = i; 
			}
			//for (int i=1;i<=N;i++)printf("%d: A=%lld nxtblk=%d step=%d\n",i,A[i],nxtblk[i],step[i]);
		}
	}
}
