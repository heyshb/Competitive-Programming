#include <bits/stdc++.h>

using namespace std;

int N,Q;
int A[100010];
int L[100010],R[100010];

struct Node
{
	int ls,rs,S;
}T[5000010];
int cnt,root[100010];

int modify(int x,int l,int r,int pos,int delta)
{
	int now = ++cnt;
	T[now].S = T[x].S + delta;
	T[now].ls = T[now].rs = 0;
	if (l==r) return now;
	int mid = (l+r)>>1;
	if (pos <= mid)
	{
		T[now].rs = T[x].rs;
		T[now].ls = modify(T[x].ls,l,mid,pos,delta);
	}
	else
	{
		T[now].ls = T[x].ls;
		T[now].rs = modify(T[x].rs,mid+1,r,pos,delta);
	}
	return now;
}

int query(int x,int l,int r,int ql,int qr)
{
	if (!x) return 0;
	if (ql<=l && qr>=r) return T[x].S;
	int mid = (l+r) >> 1;
	if (qr<=mid) return query(T[x].ls,l,mid,ql,qr);
	else if (ql>mid) return query(T[x].rs,mid+1,r,ql,qr);
	else return query(T[x].ls,l,mid,ql,qr) + query(T[x].rs,mid+1,r,ql,qr);
}

int main()
{
	int Casi;
	scanf("%d",&Casi);
	while(Casi--)
	{
		T[0].ls = T[0].rs = T[0].S = 0;
		root[0] = 0;
		cnt = 0;
		scanf("%d%d",&N,&Q);
		for (int i=1;i<=N;i++)scanf("%d",&A[i]);
		A[0] = A[N+1] = -1;
		for (int i=1;i<=N;i++)
		if (A[i]==A[i-1])
			L[i] = L[i-1];
		else
			L[i] = i;
			
		for (int i=N;i>=1;i--)
		if (A[i]==A[i+1])
			R[i] = R[i+1];
		else
			R[i] = i;
		
		int nowcnt = 0;
		for (int i=1;i<=N;i++)
		if (A[i] == A[i-1])
		{
			nowcnt++;
			root[i] = modify(root[i-1],1,N,nowcnt-1,-1);
			root[i] = modify(root[i],1,N,nowcnt,1);
		}
		else
		{
			nowcnt = 1;
			root[i] = modify(root[i-1],1,N,1,1);
		}
		while(Q--)
		{
			int QL,QR,K;
			scanf("%d%d%d",&QL,&QR,&K);
			int v1 = query(root[QR],1,N,K,N), v2 = query(root[QL-1],1,N,K,N);
			//printf("%d %d\n",v1,v2);
			int ans = v1 - v2;
			if (A[QL] == A[QL-1])
			{
				int DL,DR;
				DL = QL - L[QL];
				DR = R[QL] - QL + 1;
				//printf("%d %d\n",DL,DR);
				if (DL + DR >= K)
				{
					//if (DR >= K && DL < K) 
					if (DR >= K && DL >= K) ans++;
					if (DR < K && DL < K) ans--;
					//if (DR < K && DL >= K)
				}
			}	
			printf("%d\n",ans);
		}
	}
}
