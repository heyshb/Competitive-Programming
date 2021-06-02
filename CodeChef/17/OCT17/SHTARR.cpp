#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010010
#define MAXB 1010
int N;
int A[MAXN];
int blk;
int bl[MAXN];
int L[MAXB],R[MAXB];
int fa[MAXN];
vector<int>e[MAXN];
int stk[MAXB],top;
int nxt[MAXN];
int len[MAXB],v[MAXB][MAXB];

void rebuild(int b)
{
	int nowmax = 0;
	len[b] = 0;
	for (int i=L[b];i<=R[b];i++)
	if (A[i] > nowmax)
	{
		nowmax = A[i];
		v[b][++len[b]] = A[i];
	}
}

void update(int pos,int x)
{
	int b = bl[pos];
	A[pos] += x;
	
	rebuild(b);
}

int query(int pos,int down,int up)
{
	int res = 0;
	int b = bl[pos];
	for (int i=pos;i<=R[b];i++)
	if (A[i] >= down) 
	{
		res++;
		down = A[i] + 1;
		if (down > up) return res; 
	}
	for (int bb=b+1;bb<=blk;bb++)
	{
		if (v[bb][len[bb]] < down) continue;
		if (v[bb][len[bb]] >= up)
		{
			for (int j=1;j<=len[bb];j++)
			{
				if (v[bb][j] >= down) res++;
				if (v[bb][j] >= up) return res;
			}
		}
		int l = 0, r = len[bb],mid;
		while(l < r - 1)
		{
			mid = (l + r) >> 1;
			if (v[bb][mid] >= down)
				r = mid;
			else
				l = mid;
		}
		res += len[bb] - r + 1;
		down = v[bb][len[bb]] + 1;
		if (down > up) break;
	}
	
	return res;
}

int main()
{
	freopen("SHT.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int Q;
		scanf("%d%d",&N,&Q);
		blk = min(int(sqrt(N) + 0.5) * 4, N);
		//blk = int(sqrt(N) + 0.5);
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&A[i]);
			bl[i] = i / blk + 1;
			if (!L[bl[i]]) L[bl[i]] = i;
			R[bl[i]] = i;
		}
		blk = bl[N];
		for (int i=1;i<=N + blk;i++)
		{
			fa[i] = 0;
		}
		for (int b=1;b<=blk;b++)
			rebuild(b);
		while(Q--)
		{
			char ch[2];
			int pos,x,y;
			scanf("%s",&ch);
			if (ch[0] == '+')
			{
				scanf("%d%d",&pos,&x);
				update(pos,x);
			}
			else
			{
				scanf("%d%d%d",&pos,&x,&y);
				printf("%d\n",query(pos,x,y));
			}
		}
		for (int i=1;i<=blk;i++)L[i] = R[i] = 0;
	}

}
