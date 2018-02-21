#include <bits/stdc++.h>

using namespace std;

#define MAXNODE 10000010
#define MAXDEP 32
struct Node
{
	int ls,rs;
}T[MAXNODE];

int cnt;
int digit[40];
unordered_map<int,int>num;
int numcnt;

void getnum(int x)
{
	for (int i=1;i<=MAXDEP;i++)
	{
		digit[i] = x%2;
		x/=2;
	}
}

int insert(int ori,int dep)
{
	int now = ++cnt;
	if (dep == 0)
		return now;
	if (digit[dep])
	{
		T[now].ls = T[ori].ls;
		T[now].rs = insert(T[ori].rs,dep-1);
	}
	else
	{
		T[now].rs = T[ori].rs;
		T[now].ls = insert(T[ori].ls,dep-1);
	}
	return now;
}

int getmax(int x,int dep)
{
	if (dep == 0) return 0;
	if (digit[dep])
	{
		if (T[x].ls)
			return getmax(T[x].ls,dep-1) + (1<<(dep-1));
		else
			return getmax(T[x].rs,dep-1);
	}
	else
	{
		if (T[x].rs)
			return getmax(T[x].rs,dep-1) + (1<<(dep-1));
		else
			return getmax(T[x].ls,dep-1);
	}
}

int getmin(int x,int dep)
{
	if (dep == 0) return 0;
	if (digit[dep])
	{
		if (T[x].rs)
			return getmin(T[x].rs,dep-1);
		else
			return getmin(T[x].ls,dep-1) + (1<<(dep-1));
	}
	else
	{
		if (T[x].ls)
			return getmin(T[x].ls,dep-1);
		else
			return getmin(T[x].rs,dep-1) + (1<<(dep-1));
	}
}



int N,Q,R;
int value[300010];
int root[300010];
vector<int>e[300010];

void dfs(int x,int fa)
{
	getnum(value[x]);
	root[x] = insert(root[fa],MAXDEP);
	for (auto t:e[x])
	if (t!=fa)
		dfs(t,x);
}

int getnumber(int x)
{
	if (!num[x])
		num[x] = ++numcnt;
	return num[x];
}

int main()
{
	cnt = 0;
	numcnt = 0;
	scanf("%d%d",&N,&Q);
	scanf("%d",&R);
	R = getnumber(R);
	scanf("%d",&value[R]);
	for (int i=1;i<N;i++)
	{
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		u = getnumber(u);
		v = getnumber(v);
		e[u].push_back(v);
		e[v].push_back(u);
		value[u] = k;
	}
	dfs(R,0);
	/*
	for (int i=1;i<=N;i++)
		printf("%d root: %d\n",i,root[i]);
	for (int i=1;i<=cnt;i++)
		printf("%d: %d %d\n",i,T[i].ls,T[i].rs);*/
	int lastans = 0;
	while(Q--)
	{
		int type,u,v,k;
		scanf("%d",&type);
		type ^= lastans;
		if (type == 0)
		{
			scanf("%d%d%d",&v,&u,&k);
			v ^= lastans;
			u ^= lastans;
			k ^= lastans;
			//printf("Insert %d %d %d\n",v,u,k);
			u = getnumber(u);
			v = getnumber(v);
			getnum(k);
			value[u] = k;
			root[u] = insert(root[v],MAXDEP);
		}
		else
		{
			scanf("%d%d",&v,&k);
			v ^= lastans;
			k ^= lastans;
			//printf("Query %d %d\n",v,k);
			v = getnumber(v);
			getnum(k);
			int v1 = getmin(root[v],MAXDEP);
			int v2 = getmax(root[v],MAXDEP);
			printf("%d %d\n",v1,v2);
			lastans = v1 ^ v2;
		}
	}
}
